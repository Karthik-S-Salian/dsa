from pathlib import Path
import re

base_path = Path(".")

l= []

for p in base_path.glob("*/*"):
    if p.is_file:
        
        matches = re.findall("[0-9]+",p.name)
        l.append(matches[0])

print(len(set(l)))

l = list(set(l))
l.sort()

s=""
for n in l:
    s+=n+"\n"
with open("no.txt","w") as fh:
    fh.write(s)