
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <curl/curl.h>

#define MAX_THREADS 5  // Define the max number of concurrent downloads

typedef struct {
    char url[256];
    char filename[100];
} DownloadTask;

void *download_file(void *arg) {
    DownloadTask *task = (DownloadTask *)arg;
    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(task->filename, "wb");
        if (!fp) {
            fprintf(stderr, "Error opening file: %s\n", task->filename);
            return NULL;
        }

        curl_easy_setopt(curl, CURLOPT_URL, task->url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        
        printf("Downloading: %s\n", task->url);
        res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            fprintf(stderr, "Failed to download %s: %s\n", task->url, curl_easy_strerror(res));
        } else {
            printf("Download Complete: %s\n", task->filename);
        }

        fclose(fp);
        curl_easy_cleanup(curl);
    }
    return NULL;
}

int main() {
    DownloadTask tasks[MAX_THREADS] = {
        {"https://example.com/file1.jpg", "file1.jpg"},
        {"https://example.com/file2.jpg", "file2.jpg"},
        {"https://example.com/file3.jpg", "file3.jpg"},
        {"https://example.com/file4.jpg", "file4.jpg"},
        {"https://example.com/file5.jpg", "file5.jpg"}
    };

    pthread_t threads[MAX_THREADS];

    curl_global_init(CURL_GLOBAL_ALL);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, download_file, (void *)&tasks[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    curl_global_cleanup();
    printf("All downloads completed!\n");

    return 0;
}
