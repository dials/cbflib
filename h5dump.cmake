execute_process(
  COMMAND "$<TARGET_FILE:h5dump>" "${input-file}"
  COMMAND "$<TARGET_FILE:cbf_tail>" -n 1
  OUTPUT_FILE "${output-file}"
  RESULT_VARIABLE results
  ERROR_VARIABLE error)
foreach(result IN LISTS results)
  if(result)
    message(FATAL_ERROR "failed: ${error}")
  endif()
endforeach()
