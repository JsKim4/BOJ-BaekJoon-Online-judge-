import java.lang.Integer.min
import java.util.*

fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    val firstApple = sc.nextInt()
    val firstOrange = sc.nextInt()
    val secondApple = sc.nextInt()
    val secondOrange = sc.nextInt()
    println(min(firstApple + secondOrange, firstOrange + secondApple))
}