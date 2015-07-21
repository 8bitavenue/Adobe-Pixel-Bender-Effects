kernel Circle
<   namespace : "8bitavenue";
    vendor : "8bitavenue";
    version : 1;
>
{
  //Circle center x, y
  parameter float2 center
  <
      minValue: float2(0);
      maxValue: float2(750);
      defaultValue: float2(180);
  >;

  //Circle radius
  parameter float radius
  <
     minValue: 0.0;
     maxValue: 750.0;
     defaultValue: 30.0;
  >;

  //Circle shift (right, left)
  parameter float2 shift
  <
        minValue: float2(-750);
        maxValue: float2(750);
        defaultValue: float2(0);
  >;

  //Background color (R, G, B, A)
  parameter pixel4 color
  <
     minValue: float4(0.0,0.0,0.0,0.0);
     maxValue: float4(1.0,1.0,1.0,1.0);
     defaultValue: float4(0.2, 0.2, 0.2, 1.0);
  >;

  //Input image
  input image4 frontImage;

  //Destination image
  output pixel4 dst;

  //Apply for each pixel
  void evaluatePixel()
  {
     //Vector from circle center to current pixel
     float2 coord_for_this_pixel = outCoord() - center;

     //Length of the radius
     float cur_radius = length(coord_for_this_pixel);

     //Sample pixel and take shift into consideration
     float4 frontPixel = sampleNearest(frontImage, outCoord() - shift);

     //Background color if pixel is outside the circle
     if (cur_radius > radius)
     {      
        dst = color;
     }
     //Otherwise keep the original color
     else 
     {
        dst = frontPixel;
     }
  }
}
