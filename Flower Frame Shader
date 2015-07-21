kernel Flower
<   namespace : "Konta";
    vendor : "Konta";
    version : 1;
>
{

 //Center (x, y)
 parameter float2 center
 <
  minValue: float2(0);
  maxValue: float2(750);
  defaultValue: float2(180);
 >;

 //Background color (RGBA)
 parameter pixel4 color
 <
  minValue: float4(0.0,0.0,0.0,0.0);
  maxValue: float4(1.0,1.0,1.0,1.0);
  defaultValue: float4(0.0,0.0,0.0,0.0);
 >;

 //How big it is
 parameter float size
 <
  minValue: 1.0;
  maxValue: 1000.0;
  defaultValue: 200.0;
 >;

 //Number of leaves
 parameter float count
 <
  minValue: 1.0;
  maxValue: 100.0;
  defaultValue: 3.0;
 >;

 //Input image shift
 parameter float2 shift
 <
  minValue: float2(-750);
  maxValue: float2(750);
  defaultValue: float2(0);
 >;

 //Input image
 input image4 src;

 //Output image
 output pixel4 dst;

 //The flower is generated using a polar graph
 //as indicated below
 void evaluatePixel()
 {
  float2 coord_for_this_pixel = outCoord() - center;
       
  float cur_radius = length(coord_for_this_pixel);
		
  float x = outCoord().x-center.x;
	
  float y = outCoord().y-center.y;
        
  float theta = atan(y/x);
        
  float radius = size*abs(sin(count*theta));

  //Current pixel outside the graph, color it with background color
  if (cur_radius > radius) 
  {
   dst = color;
  }
  //Current pixel inside, keep it as it was
  else 
  {
   dst = sampleNearest(src, coord_for_this_pixel + center - shift);
  }
 }
}
