//WRITTEN BY GEMINI AI

fn area_downsample(
    input: &[u8],
    in_width: u32,
    in_height: u32,
    out_width: u32,
    out_height: u32,
) -> Vec<u8> {
    // Check if output dimensions are valid
    if out_width > in_width || out_height > in_height {
        panic!("Output dimensions cannot be greater than input dimensions.");
    }

    // Calculate downsample ratios
    let width_ratio = in_width as f64 / out_width as f64;
    let height_ratio = in_height as f64 / out_height as f64;

    // Allocate memory for output image
    let mut output_img = Vec::with_capacity((out_width * out_height) as usize);
    unsafe {
        output_img.set_len((out_width * out_height) as usize);
    }

    for y in 0..out_height {
        for x in 0..out_width {
            // Calculate area covered by the output pixel in the input image
            let in_y_start = (y as f64 * height_ratio).floor() as u32;
            let in_y_end =
                f64::min((y as f64 + 1.0) * height_ratio, in_height as f64).floor() as u32;
            let in_x_start = (x as f64 * width_ratio).floor() as u32;
            let in_x_end = f64::min((x as f64 + 1.0) * width_ratio, in_width as f64).floor() as u32;

            // Accumulate intensity values within the area
            let mut intensity_sum: u32 = 0;
            for in_y in in_y_start..in_y_end {
                for in_x in in_x_start..in_x_end {
                    intensity_sum +=
                        input[in_y as usize * in_width as usize + in_x as usize] as u32;
                }
            }

            // Average intensity for the output pixel
            let area = (in_y_end - in_y_start) * (in_x_end - in_x_start);
            output_img[y as usize * out_width as usize + x as usize] =
                ((intensity_sum as u32 + area / 2) / area) as u8;
        }
    }

    output_img
}
