function decodeUplink(input) {
  var messageString = ""
  var i = 0
  
  bytes = input.bytes
  
  while(bytes[i]!=0){
    messageString += String.fromCharCode(bytes[i])
    i++
  }
  
  i++
  
  var messageCount = bytes[i]
  
  return {
    data: {
      message: messageString,
      counter: messageCount,
      zzzRest:input.bytes
    },
    warnings: [],
    errors: []
  };
}
