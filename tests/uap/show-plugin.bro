# @TEST-EXEC: bro -NN VR::UAP |sed -e 's/version.*)/version)/g' >output
# @TEST-EXEC: btest-diff output
