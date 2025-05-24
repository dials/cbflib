from sys import argv

# version of pycbf_test1 with write logic added
import pycbf
object = pycbf.cbf_handle_struct()
newobject = pycbf.cbf_handle_struct()
object.read_file(argv[1].encode(),pycbf.MSG_DIGEST)
object.rewind_datablock()
with open(argv[2],'w',newline='\n') as f:
    print("Found",object.count_datablocks(),"blocks",file=f)
    object.select_datablock(0)
    print("Zeroth is named",object.datablock_name(),file=f)
    newobject.force_new_datablock(object.datablock_name());
    object.rewind_category()
    categories = object.count_categories()
    for i in range(categories):
        print("Category:",i, end= ' ', file=f)
        object.select_category(i)
        category_name = object.category_name()
        print("Name:",category_name, end=' ', file=f)
        newobject.new_category(category_name)
        rows=object.count_rows()
        print("Rows:",rows, end=' ', file=f)
        cols = object.count_columns()
        print("Cols:",cols,file=f)
        loop=1
        object.rewind_column()
        while loop==1:
            column_name = object.column_name()
            print("column name \"",column_name,"\"", end=' ', file=f)
            newobject.new_column(column_name)
            try:
               object.next_column()
            except:
                break
        print(file=f)
        for j in range(rows):
            object.select_row(j)
            newobject.new_row()
            object.rewind_column()
            print("row:",j,file=f)
            for k in range(cols):
                name=object.column_name()
                print("col:",name, end=' ', file=f)
                object.select_column(k)
                newobject.select_column(k)
                typeofvalue=object.get_typeofvalue()
                print("type:",typeofvalue,file=f)
                if typeofvalue.find(b"bnry") > -1:
                    s=object.get_integerarray_as_string()
                    print(len(s), file=f)
                    (compression, binaryid, elsize, elsigned, \
                        elunsigned, elements, minelement, maxelement, \
                        byteorder,dimfast,dimmid,dimslow,padding) = \
                        object.get_integerarrayparameters_wdims_fs()
                    if dimfast==0:
                        dimfast = 1
                    if dimmid==0:
                        dimmid = 1
                    if dimslow == 0:
                        dimslow = 1
                    print("compression: ",compression,file=f)
                    print("binaryid", binaryid, file=f)
                    print("elsize", elsize, file=f)
                    print("elsigned", elsigned, file=f)
                    print("elunsigned",elunsigned,file=f)
                    print("elements", elements, file=f)
                    print("minelement", minelement, file=f)
                    print("maxelement", maxelement, file=f)
                    print("byteorder", byteorder, file=f)
                    print("dimfast", dimfast, file=f)
                    print("dimmid", dimmid, file=f)
                    print("dimslow",dimslow,file=f)
                    print("padding", padding, file=f)
                    newobject.set_integerarray_wdims_fs(\
                      pycbf.CBF_BYTE_OFFSET,binaryid,s,elsize,elsigned,\
                      elements,byteorder,dimfast,dimmid,dimslow,padding)
                    try:
                       import numpy
                       d = numpy.frombuffer(s,numpy.uint32)
                       # Hard wired Unsigned Int32
                       print(d.shape, file=f)
                       print(d[0:10],d[int(d.shape[0]/2)],d[len(d)-1],file=f)
                       print(d[int(d.shape[0]/3):int(d.shape[0]/3+20)], file=f)
                       d=numpy.reshape(d,(2300,2300))
    #                   from matplotlib import pylab
    #                   pylab.imshow(d,vmin=0,vmax=1000)
    #                   pylab.show()
                    except ImportError:
                       print("You need to get numpy and matplotlib to see the data", file=f)
                else:
                    value=object.get_value()
                    newobject.set_value(value)
                    print("Val:",value,i,file=f)
        print(file=f)
    del(object)
    newobject.write_widefile(argv[3].encode(),pycbf.CBF,\
        pycbf.MIME_HEADERS|pycbf.MSG_DIGEST|pycbf.PAD_4K,0)
    #
    #object.free_handle(handle)
