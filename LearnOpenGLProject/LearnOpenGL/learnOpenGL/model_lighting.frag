#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;


uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 careraPos;
uniform samplerCube skybox;
uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;

void main()
{    
    vec4 diffuseColor = texture(texture_diffuse1, TexCoords);
    vec4 specColor = texture(texture_specular1, TexCoords);
    vec3 lightDir = normalize(lightPos - FragPos);
    vec3 normal = normalize(Normal);

    // ambient
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
    float halfLambert = dot(normal, lightDir) * 0.5 + 0.5;
    vec3 diffuse = halfLambert * lightColor * diffuseColor.xyz;
    
    // specular
    float specularStrength = 0.5;
    vec3 viewDir    = normalize(viewPos - FragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), 32);
    vec3 specular = lightColor * spec * specColor.xyz;
        
    vec3 result = ambient + diffuse + specular;
  
    FragColor = vec4(result, 1.0);


    // refract
    float ratio = 1.00 / 1.52;
    vec3 I = normalize(FragPos - careraPos);
    vec3 R = refract(I, normalize(Normal), ratio);
    FragColor = texture(skybox, R);


}