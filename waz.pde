ArrayList<Integer> x = new ArrayList<Integer>();
ArrayList<Integer> y = new ArrayList<Integer>();
int w = 30, h = 30, blocks = 20, dir = 2, foodx = 15, foody =15, speed =10;
int[]x_dir = {0,0,1,-1} , y_dir = {1,-1,0,0};
boolean gameover = false;
int game = 0;



void setup(){
background(0);
size(600,600);
x.add(0);
y.add(15);
textAlign(CENTER);
textSize(30);
fill(0,244,0);
text("PRESS ENTER TO START",width/2,height/2);
}

void draw(){
  if(game!=0){
    
  background(0);
  fill(60,170,50);
  for(int i = 0; i<x.size();i++){
  rect(x.get(i)*blocks,y.get(i)*blocks,blocks,blocks); 
  }
  
  if(!gameover){
    
    fill(255);
    rect(foodx*blocks,foody*blocks,blocks,blocks);
    textAlign(LEFT);
    textSize(25);
    fill(255);
    text("Score:" + x.size(),10,10);
    if(frameCount%speed==0){
      x.add(0,x.get(0) + x_dir[dir]);
      y.add(0,y.get(0) + y_dir[dir]);
       
      if(x.get(0) < 0 || y.get(0) < 0 ||x.get(0) >=w || y.get(0) >=h) gameover = true;
      for(int i = 1; i<x.size();i++)
      if(x.get(0) == x.get(i) && y.get(0)==y.get(i)) gameover =true;
      
      if(x.get(0)==foodx && y.get(0)==foody){
        
        if(x.size()%5==0 && speed >=3) speed -=1;
        
        foodx = (int) random(0,w);
        foody = (int) random(0,h);
        
      }else{
        x.remove(x.size()-1);
        y.remove(y.size()-1);
      }
    }
  }else{
    
   fill(250,190,20);
   textSize(30);
   textAlign(CENTER);
   text("GAME OVER\n SCORE:"+x.size()+"\n PRESS ENTER TO RESTART",width/2,height/3);
   
   if(keyCode==ENTER){
   x.clear();
   y.clear();
   x.add(0);
   y.add(15);
   dir = 2;
   speed = 10;
   gameover = false;
   }
   
  }
 }
}

void keyPressed(){
   if(game==0 && keyCode==ENTER){
     game =1;
   }
  
  
  int newdire = keyCode ==DOWN?0:(keyCode==UP?1:(keyCode==RIGHT?2:(keyCode==LEFT?3:-1)));
  if(newdire != -1) dir = newdire;
}
