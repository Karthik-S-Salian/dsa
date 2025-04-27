class WindowNode:
    def __init__(self,window_id):
        self.window_id = window_id

    def is_window(self):
        return True
    
class IntermediateNode:
    def __init__(self,split_direction):
        self.left = None
        self.right = None
        self.split_direction = split_direction

    def is_window(self):
        return False
    
    @staticmethod
    def get_opposite_split(split):
        return "H" if split=="V" else "V"

class WindowManager:
    def __init__(self):
        self.tree = None
        self.active_windows  = []
        self.windows = set()
        self.insert_count = 1
        self.directions = ["H", "V", "H", "V"] 

    def add(self,id):
        def find(node,parent:WindowNode | IntermediateNode | None,dir:str):
            if node.is_window():
                if node.window_id == self.active_windows[-1]:
                    direction  = self.directions[self.insert_count % 4]
                    new_node = IntermediateNode(direction)
                    if self.insert_count%4<2:
                        new_node.left = WindowNode(id)
                        new_node.right = node
                    else:
                        new_node.left = node
                        new_node.right = WindowNode(id)

                    if parent:
                        if dir=="left":
                            parent.left = new_node
                        else:
                            parent.right = new_node
                    if self.tree == node:
                        self.tree=new_node
                    return True
                return False
            
            if not find(node.left,node,"left"):
                return find(node.right,node,"right")
            return  True
        
        if not self.active_windows:
            self.tree = WindowNode(id)
        else:
            if not find(self.tree,None,"left"):
                raise Exception("unknown window id")
        self.active_windows.append(id)
        self.windows.add(id)
        self.insert_count +=1

    def set_active(self,id):
        self.active_windows.append(id)

    def delete(self):
        def find(node:WindowNode | IntermediateNode,parent:WindowNode | IntermediateNode | None,prvs_parent:WindowNode | IntermediateNode | None,dir:str,prvs_dir:str):
            if node.is_window():
                if node.window_id == self.active_windows[-1]:
                    if dir=="left":
                        other_node = parent.right
                    else:
                        other_node = parent.left
                    if prvs_parent:
                        if prvs_dir == "left":
                            prvs_parent.left = other_node
                        else:
                            prvs_parent.right = other_node
                    else:
                        self.tree = other_node
                    return True
                return False
            
            if not find(node.left,node,parent,"left",dir):
                return find(node.right,node,parent,"right",dir)
            return  True
        
        if self.tree.is_window():
            self.tree = None
        else:
            if not find(self.tree,None,None,"left","left"):
                raise Exception("unknown window id")
            
        self.windows.remove(self.active_windows[-1])
        while self.active_windows and self.active_windows[-1] not in self.windows:
            self.active_windows.pop()


    def find_grid_size(self,node:WindowNode | IntermediateNode|None):
        if node is None:
            return 0,0
        if node.is_window():
            return 1,1
        
        lh,lv = self.find_grid_size(node.left)
        rh,rv = self.find_grid_size(node.right)

        h = max(lh,rh)
        v= max(lv,rv)

        if node.split_direction=="H":
            h*=2
        else:
            v*=2
        return h,v
    
    def get_grid(self):

        h,v = self.find_grid_size(self.tree)

        grid =  [ [0]*h for _ in range(v)]

        def fill(xs,xe,ys,ye,val):
            for i in range(ys,ye):
                for j in range(xs,xe):
                    grid[i][j] = val

        def generate_grid(node,xs,xe,ys,ye):
            if node.is_window():
                fill(xs,xe,ys,ye,node.window_id)
            else:
                if node.split_direction=="H":
                    diff = xe-xs
                    generate_grid(node.left,xs,xs + diff//2,ys,ye)
                    generate_grid(node.right,xs + diff//2,xe,ys,ye)
                else:
                    diff = ye - ys
                    generate_grid(node.left,xs,xe,ys,ys + diff//2)
                    generate_grid(node.right,xs,xe,ys + diff//2,ye)

        if self.tree:
            generate_grid(self.tree,0,h,0,v)
        for row in grid:
            print(row)
        print("")

wm = WindowManager()

wm.get_grid()
wm.add(1)
wm.get_grid()
wm.add(2)
wm.get_grid()
wm.add(3)
wm.get_grid()
wm.add(4)
wm.get_grid()
wm.add(5)
wm.get_grid()
wm.add(6)
wm.get_grid()
wm.add(7)
wm.get_grid()

    
