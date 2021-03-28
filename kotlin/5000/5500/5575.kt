import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    val first = sc.nextLine().split(" ")
    val second = sc.nextLine().split(" ")
    val last = sc.nextLine().split(" ")
    println(secondToDate(first.calculationTime()))
    println(secondToDate(second.calculationTime()))
    println(secondToDate(last.calculationTime()))
}

fun List<String>.calculationTime(): Int {
    val hourFirst = this[0].toInt()
    val minuteFirst = this[1].toInt()
    val secondFirst = this[2].toInt()
    val hourSecond = this[3].toInt()
    val minuteSecond = this[4].toInt()
    val secondSecond = this[5].toInt()
    val first = toSecond(hourFirst, minuteFirst, secondFirst)
    val second = toSecond(hourSecond, minuteSecond, secondSecond)
    return second - first
}

fun toSecond(hourFirst: Int, minuteFirst: Int, secondFirst: Int): Int =
    hourFirst * 60 * 60 + minuteFirst * 60 + secondFirst

fun secondToDate(second: Int): String = "${second / 3600} ${second % 3600 / 60} ${second % 60}"