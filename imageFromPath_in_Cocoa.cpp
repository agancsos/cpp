- (NSImage*)imageFromPath:(NSString*)path{
    NSImage* image3=[[[NSImage alloc]initWithContentsOfFile:path]autorelease];
    return image3;
}

