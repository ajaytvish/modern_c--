
// Specifying underlying type as `unsigned int` & bool
enum class Color : unsigned int { Red = 0xff0000, Green = 0xff00, Blue = 0xff };
// `Red`/`Green` in `Alert` don't conflict with `Color`
enum class Alert : bool { Red, Green };
int main() 
{
    Color c = Color::Red;// Specifying underlying type as `unsigned int`
}
