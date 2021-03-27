import java.util.*

fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    val month = sc.nextInt()
    val date = sc.nextInt()
    println(getDateString(month, date))
}


fun getDateString(month: Int, date: Int): String = when {
    month < 2 || (month == 2 && date < 18) -> "Before"
    month > 2 -> "After"
    else -> "Special"
}