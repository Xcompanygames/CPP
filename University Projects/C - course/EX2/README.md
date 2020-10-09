# C
 


תרגיל:

נתונה המטריצה הבאה:

T	R	A	C
K	A	T	E
E	M	S	E
N	P	L	L

מתוך הטבלה אפשר לבנות מילים בצורה הבאה:
אפשר להתחיל מכל משבצת ואז ללכת ימינה , שמאלה , למעלה או למטה.

לדוגמא המילה CAT  : 

T	R	A
C

K	A	T	E
E	M	S	E
N	P	L	L


שימו לב שניתן ליצור גם את המילה CATS :

T	R	A	C

K	A	T
E
E	M	S
E
N	P	L	L


אלו שתי מילים נפרדות.

הכלל הוא שניתן ללכת ללא הגבלה אך אסור לקו הדמיוני שיצרנו לחצות את עצמו למשל הדרך הבא אינה חוקית :
T	R	A	C

K	A	T	E
E	M	S	E
N	P	L	L


המילה   CATSEETAM אינה חוקית , ראשית כי איננה מילה וחוץ מזה הקו חוצה את עצמו.



לפני שתמשיכו בקריאת התרגיל נסו למצוא כמה מילים אפשר לחלץ מהמטריצה הנ״ל.
אני מצאתי 20 מילים האם תוכלו למצוא את כולן ? 
הערה :  בהחלט ייתכן שישנן עוד מילים .

התרגיל:
יש לכתוב תוכנית שמגדירה את המטריצה הנ״ל וקוראת לפונקציה 
#define MATRIX_SIZE 4
 int printWords(char A[MATRIX_SIZE][MATRIX_SIZE])

הפונקציה הנ״ל עוברת על המטריצה ועל כל הצירופים האפשריים ומדפיסה את כל המילים שיש במטריצה ומחזירה את כמות המילים שמצאה.

לצורך מימוש תצטרכו את הפונקציה 
bool isWord(char* s)
הפונקציה הנ״ל מקבלת מצביע לרצף של תווים ומחזירה האם רצף זה הוא מילה או לא.
שימו לב כי רצף האותיות במילה מסתיים תמיד  ב ‘\0’.

להלן מימוש הפונקציה :
bool isWord(char* s){

		return (!strcmp(s,"CAT") |
			!strcmp(s,"CATS") |
			!strcmp(s,"TRAM") |
			!strcmp(s,"TRAMS") |
			!strcmp(s,"TAME") |
			!strcmp(s,"CAR") |
			!strcmp(s,"CARS") |
			!strcmp(s,"RAT") |
			!strcmp(s,"RATS") |
			!strcmp(s,"RAMP") |
			!strcmp(s,"ART") |
			!strcmp(s,"CART") |
			!strcmp(s,"STAMP") |
			!strcmp(s,"TAKEN") |
			!strcmp(s,"MEN") |
			!strcmp(s,"MAKE") |
			!strcmp(s,"TAKE") |
			!strcmp(s,"ATE") |
			!strcmp(s,"SELL") |
			!strcmp(s,"STEEL") |
			!strcmp(s,"RAKE") );

}

הרצה תקינה תדפיס 20 מילים למסך.


