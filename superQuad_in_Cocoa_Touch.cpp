- (NSString*)superQuad: (float) a b:(float) b c:(float) c{

            float nA=-b-(sqrt((b*b)-(4*a*c)))/(2*a);
            float pA=-b+(sqrt((b*b)-(4*a*c)))/(2*a);
            NSString *temp;
            temp=[NSString stringWithFormat:@\"Lower: %.4f\",nA];
            temp=[temp stringByAppendingString:[NSString stringWithFormat:@\"
Upper: %.4\",pA]];

             return temp;
}
