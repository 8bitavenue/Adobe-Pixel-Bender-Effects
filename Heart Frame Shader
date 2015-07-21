kernel Heart
<   namespace : "8bitavenue";
    vendor : "8bitavenue";
    version : 1;
>
{
 //Heart center (x, y)
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
  defaultValue: float4(0.0,0.0,0.0,1.0);
 >;

 //How big it is
 parameter float size
 <
  minValue: 1.0;
  maxValue: 100000.0;
  defaultValue: 1000.0;
 >;

 //Heart shape
 parameter float skew
 <
  minValue: 1.0;
  maxValue: 1000.0;
  defaultValue: 100.0;
 >;

 //Input image shift (left, right)
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

 //The heart has a magic equation
 //Radius = some function in terms of (x, y)
 void evaluatePixel()
 {
  float2 coord_for_this_pixel = outCoord() - center;
        
  float cur_radius = length(coord_for_this_pixel);
		
  float x = outCoord().x-center.x;
	
  float y = outCoord().y-center.y;
        
  float radius = pow(x*x + y*y - size, 3.0) + skew*x*x*y*y*y;

  //Use background color if the pixel is outside the heart
  if (cur_radius < radius) 
  {
   dst = color;
  }
  //Otherwise keep the color as it was
  else 
  {
   dst = sampleNearest(src, coord_for_this_pixel + center - shift);
  }
 }
}

