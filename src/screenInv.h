//Configuration
#define		SI_CONTROL_PIPE		"/tmp/invertScreen"
#define		SI_CONFIG_FILE		"/mnt/onboard/.kobo/nightmode.ini"
#define 	SI_DEBUG_LOGPATH    "/mnt/onboard/.kobo/screenInvertLog"
#define		SI_AREA_THRESHOLD	60	//percent

//for logging, compile with "make debug"
#ifdef SI_DEBUG
#define DEBUGPRINT(_fmt, ...) \
        do { \
            FILE *logFP = fopen(SI_DEBUG_LOGPATH, "a"); \
            struct timeval tm; \
            gettimeofday(&tm, NULL); \
            if(logFP) { fprintf(logFP, "%ld.%06ld ", (long int)tm.tv_sec, (long int)tm.tv_usec); \
			fprintf(logFP, _fmt, ##__VA_ARGS__); \
            fclose(logFP); } \
       } while (0)
#else
#define DEBUGPRINT(_fmt, ...) /**/
#endif
