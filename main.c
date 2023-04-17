/*
* SwapCentral
* V 1.0
* Creator : Relic ( CooL-CodeR )
* Initial Release : Feb 2023
* status : v 1.0 complete
*/

#include <stdio.h>
#include <curl/curl.h>

void banner();
void menu();
int exchange_rates(void);

int main(int argc, char** argv)
{
	banner();
	exchange_rates();
	
	return 0;	
}

void banner()
{
    printf("%s", "API CHECKER PRO v 1.0\n");
}

int exchange_rates(void)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.apilayer.com/exchangerates_data/convert?to=ZAR&from=USD&amount=1");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "apikey: KeyHere");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    res = curl_easy_perform(curl);

    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl);
  }

  return (int)res;
}
