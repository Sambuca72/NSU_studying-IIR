#include <stdio.h>

typedef struct DateTime_s {
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;

int compare_dates(DateTime a, DateTime b) {
    if (a.year != b.year) return a.year - b.year;
    if (a.month != b.month) return a.month - b.month;
    if (a.day != b.day) return a.day - b.day;
    if (a.hours != b.hours) return a.hours - b.hours;
    if (a.minutes != b.minutes) return a.minutes - b.minutes;
    return a.seconds - b.seconds;
}

DateTime min(const DateTime *arr, int cnt){
    DateTime earl = arr[0];
    for (int i = 1; i<cnt;i++){
        if(compare_dates(arr[i],earl)<0){
            earl=arr[i];
        }
    }
    return earl;
}

int main(){
    freopen("Input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    DateTime dates[n];

    for (int i=0; i<n;i++){
        scanf("%d %d %d %d %d %d",
            &dates[i].year,
            &dates[i].month,
            &dates[i].day,
            &dates[i].hours,
            &dates[i].minutes,
            &dates[i].seconds);
    }
    DateTime earl = min(dates,n);
    printf("%d %d %d %d %d %d\n",earl.year,earl.month,earl.day,earl.hours,earl.minutes,earl.seconds);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

