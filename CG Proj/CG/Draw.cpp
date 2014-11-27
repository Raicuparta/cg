#include "Draw.h"


Draw::Draw(void)
{
}


Draw::~Draw(void)
{
}

void Draw::plane(int lines, int columns, float width, float height) {
	float quad_height = height/lines;
	float quad_width = width/columns;

	for (int l = 0; l < lines; l++) {
		for (int c = 0; c < columns; c++) {
			glBegin(GL_QUADS);
			glNormal3f(0, 0, 1);
			glVertex3f(c*quad_width , l*quad_height, 0);
			glVertex3f((c+1)*quad_width , l*quad_height, 0);
			glVertex3f((c+1)*quad_width , (l+1)*quad_height, 0);
			glVertex3f(c*quad_width , (l+1)*quad_height, 0);
			glEnd();
		}
	}
}

void Draw::texturedPlane(int lines, int columns, float width, float height, GLuint texture) {
	glEnable(GL_TEXTURE_2D);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, texture);
	
	float quad_height = height/lines;
	float quad_width = width/columns;

	for (int l = 0; l < lines; l++) {
		for (int c = 0; c < columns; c++) {
			glBegin(GL_QUADS);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(c*quad_width , l*quad_height, 0);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f((c+1)*quad_width , l*quad_height, 0);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f((c+1)*quad_width , (l+1)*quad_height, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(c*quad_width , (l+1)*quad_height, 0);

			glEnd();
		}
	}

	

	glDisable(GL_TEXTURE_2D);
}

void Draw::hexagonalPrism() {

	glRotatef(90, 1, 0, 0);
	double hexagonX[6];
	double hexagonY[6];

	for (int i = 0; i < 6; i++) {
		hexagonX[i] = cos((i * 3.14159265 )/ 3);
		hexagonY[i] = sin((i * 3.14159265 )/ 3);
	}

	//Front
	glNormal3d(0, 0, -1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; i++){
		glVertex3d(hexagonX[i], hexagonY[i], 0);
	}
	glEnd();

	//Back
	glNormal3d(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; i++){
		glVertex3d(hexagonX[i], hexagonY[i], 1);
	}
	glEnd();

	//Sides
	for (int i = 0; i < 6; i++){

		glBegin(GL_QUADS);
		glNormal3d(hexagonX[i], hexagonY[i], 0);
		glVertex3d(hexagonX[i], hexagonY[i], 0);

		glNormal3d(hexagonX[i + 1], hexagonY[i + 1], 0);
		glVertex3d(hexagonX[i + 1], hexagonY[i + 1], 0);

		glNormal3d(hexagonX[i + 1], hexagonY[i + 1], 0);
		glVertex3d(hexagonX[i + 1], hexagonY[i + 1], 1);

		glNormal3d(hexagonX[i], hexagonY[i], 0);
		glVertex3d(hexagonX[i], hexagonY[i], 1);
		glEnd();
	}
}

void Draw::loadTexture(const char * filename, int * width, int * height, int * size, unsigned char **pixel_data) {
    
	std::cout << "filename: " << filename << std::endl;

    FILE * fp = fopen(filename, "r");
    
    if (fp == NULL){
        std::cout << "Couldn't open file...Aborting" << std::endl;
    }
    
    short identifier = -1;
    
    fread(&identifier, 1, sizeof(short), fp);

	int filesize = -1;
    fread(&filesize, 1, sizeof(int), fp);
    int reserved = -1;
    fread(&reserved, 1, sizeof(reserved), fp);
    int bitmap_offset = -1;
    fread(&bitmap_offset, 1, sizeof(int), fp);
    int bitmap_header_size = -1;
    fread(&bitmap_header_size, 1, sizeof(int), fp);
    int bitmap_width = -1;
    fread(&bitmap_width, 1, sizeof(int), fp);
    int bitmap_heigth = -1;
    fread(&bitmap_heigth, 1, sizeof(int), fp);
    short bitmap_planes = -1;
    fread(&bitmap_planes, 1, sizeof(short), fp);
    short bits_per_pixel = -1;
    fread(&bits_per_pixel, 1, sizeof(short), fp);
    int compression = -1;
    fread(&compression, 1, sizeof(int), fp);
    int bitmap_data_size = -1;
    fread(&bitmap_data_size, 1, sizeof(int), fp);
    int hresolution = -1;
    fread(&hresolution, 1, sizeof(int), fp);
    int vresolution = -1;
    fread(&vresolution, 1, sizeof(int), fp);
    int num_colors = -1;
    fread(&num_colors, 1, sizeof(int), fp);
    int num_important_colors = -1;
    fread(&num_important_colors, 1, sizeof(int), fp);
    
    fseek(fp, bitmap_offset, SEEK_SET);
    
    unsigned char * data = new unsigned char[bitmap_data_size];
    
    fread(data, sizeof(unsigned char), bitmap_data_size, fp);
    
    *pixel_data = data;
    *size = bitmap_data_size;
    *width = bitmap_width;
    *height = bitmap_heigth;
    
    fclose(fp);
    
}