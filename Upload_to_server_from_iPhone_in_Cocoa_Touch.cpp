- (BOOL)uploadImage:(NSData *)imageData filename:(NSString *)filename{


NSString *urlString = @\"[]://artpad.computerfoxdesign.com/uploader.php\";

NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
[request setURL:[NSURL URLWithString:urlString]];
[request setHTTPMethod:@\"POST\"];

NSString *boundary = [NSString stringWithString:@\"---------------------------14737809831466499882746641449\"];
NSString *contentType = [NSString stringWithFormat:@\"multipart/form-data; boundary=%@\",boundary];
[request addValue:contentType forHTTPHeaderField: @\"Content-Type\"];

NSMutableData *body = [NSMutableData data];
[body appendData:[[NSString stringWithFormat:@\"
--%@
\",boundary] dataUsingEncoding:NSUTF8StringEncoding]];
[body appendData:[[NSString stringWithString:[NSString stringWithFormat:@\"Content-Disposition: form-data; name=\"userfile\"; filename=\"%@\"
\",filename]] dataUsingEncoding:NSUTF8StringEncoding]];
[body appendData:[[NSString stringWithString:@\"Content-Type: application/octet-stream

\"] dataUsingEncoding:NSUTF8StringEncoding]];
[body appendData:[NSData dataWithData:imageData]];
[body appendData:[[NSString stringWithFormat:@\"
--%@--
\",boundary] dataUsingEncoding:NSUTF8StringEncoding]];
[request setHTTPBody:body];

NSData *returnData = [NSURLConnection sendSynchronousRequest:request returningResponse:nil error:nil];
NSString *returnString = [[NSString alloc] initWithData:returnData encoding:NSUTF8StringEncoding];

return ([returnString isEqualToString:@\"OK\"]);
}

