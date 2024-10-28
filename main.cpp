#include "Circle.h"
#include "Rectangle.h"
#include <memory>
#include <vector>

int main()
{
	// ベクターにインスタンスを格納
	std::vector<std::unique_ptr<IShape>> shapes;

	// 明示的に unique_ptr<IShpe>型を指定
	std::unique_ptr<IShape> circle = std::make_unique<Circle>(5.0f);
	std::unique_ptr<IShape> rectangle = std::make_unique<Rectangle>(6.0f, 12.0f);

	shapes.push_back(std::move(circle));
	shapes.push_back(std::move(rectangle));

	// 各図形を表示
	for (const std::unique_ptr<IShape>& shape : shapes)
	{
		shape->Draw();
	}

	return 0;
}
