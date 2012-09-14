
function [ x1, y1 , x2, y2 ] = circleintersection ( rad1, cx1, cy1, rad2, cx2, cy2 )

   k1 = rad1*rad1 - rad2*rad2 - (cx1-cx2)*(cx1-cx2) - (cy1-cy2)*(cy1-cy2);
disp(k1, "k1 = ")
   k2 = 4*(cx1-cx2)*(cx1-cx2) + 4*(cy1-cy2)*(cy1-cy2);
disp(k2, "k2 = ")
   Da = 4*(cx1-cx2)*(cx1-cx2)*k1*k1 - 4*k2*( k1*k1-4*(cy1-cy2)*(cy1-cy2)*rad2*rad2 )
disp(Da, "Da = ")
   Db = 4*(cy1-cy2)*(cy1-cy2)*k1*k1 - 4*k2*( k1*k1-4*(cx1-cx2)*(cx1-cx2)*rad2*rad2 )
disp(Db, "Db = ")


   x1 = ( -2*(cx1-cx2)*k1 - sqrt(Da) )/k2;
disp(x1, "x1 = ")
   y1 = ( -2*(cy1-cy2)*k1 - sqrt(Db) )/k2;
disp(y1, "y1 = ")
   x2 = ( -2*(cx1-cx2)*k1 + sqrt(Da) )/k2;
disp(x2 , "x2 = ")
   y2 = ( -2*(cy1-cy2)*k1 + sqrt(Db) )/k2;
disp(y2, "y2 = ")
endfunction


function [ x1, y1 , x2, y2 ] = circleintersection2 ( rad1, cx1, cy1, rad2, cx2, cy2 )
   
   k1 = rad1/rad2;
   disp(k1, "k1 = ")
   xm = (cx1+k1*cx2)/(1+k1);
   ym = (cy1+k1*cy2)/(1+k1);
   disp(xm, "xm = ")
   disp(ym, "ym = ")
   C1M2 = (xm-cx1)*(xm-cx1) + (ym-cy1)*(ym-cy1);
   disp(C1M2, "C1M2 = ")
   S = sqrt( C1M2*(rad1*rad1-C1M2) );
   disp(S, "S = ")
   if (cx2-cx1 == 0) then
      y1 = ym;
      y2 = ym;
      x1 = (S-cx1*(ym-cy1))/ym-cy1
      x2 = (-S-cx1*(ym-cy1))/ym-cy1
   else
      c1c2yIx = (cy2-cy1)/(cx2-cx1);
      disp(c1c2yIx, "c1c2yIx = ")
      y1 = ( S+cy1*(xm-cx1)-cx1*(ym-cy1) )/( (xm-cx1) + c1c2yIx*(ym-cy1) );
   
      y2 = ( -S+cy1*(xm-cx1)-cx1*(ym-cy1) )/( (xm-cx1) + c1c2yIx*(ym-cy1) );
   
      x1 = -y1*c1c2yIx + xm + ym*c1c2yIx;
   
      x2 = -y2*c1c2yIx + xm + ym*c1c2yIx;
   end

disp(x1, "x1 = ")
disp(y1, "y1 = ")
disp(x2, "x2 = ")
disp(y2, "y2 = ")
disp(" =============================================== ")
endfunction

//rad1 = 
//xc1 = 
//yc1 = 

//rad2 = 
//xc2 = 
//yc2 = 

Rec = circleintersection2(4,0,0,4,6,0)
circleintersection2(2,0,0,4,0,5)
circleintersection2(3,0,0,3,4,4)
circleintersection2(3,0,0,5,5,5)
//printf("x1 = %f, y1 = %f, x2 = %f, y2 = %f", Rec[1],Rec[2],Rec[3],Rec[4]);