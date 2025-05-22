from sys import argv

import pycbf
obj = pycbf.cbf_handle_struct()
obj.read_file(argv[1].encode(),0)
obj.select_datablock(0)
g = obj.construct_goniometer()
with open(argv[2],'w',newline='\n') as f:
    print("Rotation axis is",g.get_rotation_axis(),file=f)
    d = obj.construct_detector(0)
    print("Beam center is",d.get_beam_center(),file=f)
    print("Detector slow axis is", d.get_detector_axis_slow(), file=f)
    print("Detector fast axis is", d.get_detector_axis_fast(), file=f)
    print("Detector axes (fast, slow) are", d.get_detector_axes_fs(), file=f)
