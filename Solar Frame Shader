kernel Sun
<   namespace : "8bitavenue";
    vendor : "8bitavenue";
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

 //Background color (R, G, B, A)
 parameter pixel4 color
 <
 	minValue: float4(0.0,0.0,0.0,0.0);
 	maxValue: float4(1.0,1.0,1.0,1.0);
	defaultValue: float4(0.0,0.0,0.0,0.0);
 >;

 //How big the frame
 parameter float size
 <
 	minValue: 1.0;
 	maxValue: 1000.0;
 	defaultValue: 100.0;
 >;

 //Length of sun beam
 parameter float len
 <
 	minValue: 1.0;
	maxValue: 1000.0;
	defaultValue: 10.0;
 >;

 //Number of sun beams
 parameter float count
 <
 	minValue: 1.0;
 	maxValue: 100.0;
 	defaultValue: 10.0;
 >;
    
 //Image shift (x, y)
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

 //Apply this filter
 void evaluatePixel()
 {
  //Vector from the current pixel to the center
  float2 coord_for_this_pixel = outCoord() - center;
        
  //Length of that vector
  float cur_radius = length(coord_for_this_pixel);
		
  //Calculate the the polar angle theta
  float x = outCoord().x-center.x;
  float y = outCoord().y-center.y;        
  float theta = atan(y/x);
        
  //Calcule the radius using the following polar graph equation
  float radius = size + len * pow(cos(count*theta), 4.0) - sin(theta);

  //Pixel outside the graph ? color it
  if (cur_radius > radius) 
  {
    dst = color;
  }
  //Pixel inside leave it as it was before
  else 
  {
    dst = sampleNearest(src, coord_for_this_pixel + center - shift);
  }
 }
}

