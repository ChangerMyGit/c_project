#include <stdio.h>
struct Point {
	int x;
	int y;
};

struct Screen {
   struct Point px;
   struct Point py;
};

typedef struct Tnode {
   struct Point *px;
   struct Point *py;
} TreeNode;
void main(){
	TreeNode tr ;
	struct Screen sc = {{1,2},{3,4}};
	struct Point pt1 = {1,2};
	struct Point pt2 = {3,4};
    //sc.px = pt1;
	//sc.py = pt2;
	tr.px = &pt1;
	tr.py = &pt2;
	printf("%d %d %d \n",sc.px.x,sc.px.y,sizeof(struct Screen));
	printf("%d %d\n",tr.px->x,tr.px->y);
}