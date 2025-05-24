import pycbf, sys
from decimal import Decimal, ROUND_HALF_UP

image_file = bytes(sys.argv[1],'utf-8')

cbf = pycbf.cbf_handle_struct()
cbf.read_widefile(image_file, pycbf.MSG_DIGEST)

with open(sys.argv[2],'w',newline='\n') as f:
    for element in range(64):
        d = cbf.construct_detector(element)
        print("element:", element, file=f)

        v00 = d.get_pixel_coordinates(0, 0)
        v01 = d.get_pixel_coordinates(0, 1)
        v10 = d.get_pixel_coordinates(1, 0)
        v11 = d.get_pixel_coordinates(1, 1)
        prec = Decimal('1.000000000')

        print('(0, 0) v00 [ %.9f %.9f %.9f ]' %(round(v00[0],9), round(v00[1],9), round(v00[2],9)), file=f)
        print('(0, 1) v01 [ %.9g %.9g %.9g ]' %(round(v01[0],9), round(v01[1],9), round(v01[2],9)), file=f)
        print('(1, 0) v10 [ %.9g %.9g %.9g ]' %(round(v10[0],9), round(v10[1],9), round(v10[2],9)), file=f)
        print('(1, 1) v11 [ %.9g %.9g %.9g ]' %(round(v11[0],9), round(v11[1],9), round(v11[2],9)), file=f)

        print("surface axes:",  d.get_detector_surface_axes(0), d.get_detector_surface_axes(1), file=f)

        print(d.get_detector_surface_axes(0), "has", cbf.count_axis_ancestors(d.get_detector_surface_axes(0)), "ancestors", file=f)
        print(d.get_detector_surface_axes(1), "has", cbf.count_axis_ancestors(d.get_detector_surface_axes(1)), "ancestors", file=f)

        cur_axis = d.get_detector_surface_axes(0)
        count = cbf.count_axis_ancestors(cur_axis)

        for index in range(count):
            print("axis", cur_axis, "index: ", index, file=f)
            print("    equipment", cbf.get_axis_equipment(cur_axis), file=f)
            print("    depends_on", cbf.get_axis_depends_on(cur_axis), file=f)
            print("    equipment_component", cbf.get_axis_equipment_component(cur_axis), file=f)
            vector = cbf.get_axis_vector(cur_axis)
            print("    vector [ %.8g %.8g %.8g ]" % (round(vector[0],7), round(vector[1],7), round(vector[2],7)), file=f)
            offset = cbf.get_axis_offset(cur_axis)
            print("    offset [ %.8g %.8g %.8g ]" % (round(offset[0],7), round(offset[1],7), round(offset[2],7)), file=f)
            print("    rotation", cbf.get_axis_rotation(cur_axis), file=f)
            print("    rotation_axis", cbf.get_axis_rotation_axis(cur_axis), file=f)
            cur_axis = cbf.get_axis_depends_on(cur_axis)
