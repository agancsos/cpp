char year[4]{

        char year[4];
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        sprintf(year,\"%d\",timePtr->tm_year+1900);

        return year;
}
