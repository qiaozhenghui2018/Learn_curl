import os
import time
source = [r'D:\\python\python_doc']

target_dir = r'D:\\python\tmp'

target = target_dir + os.sep + time.strftime('%Y%m%d%H%M%S') + '.zip'

if not os.path.exists(target_dir):
    os.mkdir(target_dir)

zip_cmd = 'C:360zip.exe -r {} {}'.format(target, ' '.join(source))

print("zip cmd is:", zip_cmd)

print("running:")

if os.system(zip_cmd) == 0:
    print("success back up to dir", target)
else:
    print("back up failed")
