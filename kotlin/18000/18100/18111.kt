import java.util.*

const val REMOVE_RESOURCE = 2
const val ADD_RESOURCE = 1


fun main() {
    val sc = Scanner(System.`in`)
    val config = sc.nextLine().split(" ")
    val row = config[0].toInt()
    val column = config[1].toInt()
    val block = config[2].toInt()
    val world = scanMap(row, column, sc)
    var min = Int.MAX_VALUE
    var minHeight = 0
    for (i: Int in 0..256) {
        val calculationFlattening = world.calculationFlattening(i, block)
        if (calculationFlattening < min) {
            min = calculationFlattening
            minHeight = i
        }
    }
    println("$min $minHeight")
}

fun Array<Array<Int>>.calculationFlattening(goalHeight: Int, possessBlock: Int): Int {
    var over = 0
    var under = 0
    for (ints in this) {
        for (blockHeight in ints) {
            if (goalHeight < blockHeight)
                over += blockHeight - goalHeight
            if (goalHeight > blockHeight)
                under += goalHeight - blockHeight
        }
    }
    if (under - over > possessBlock)
        return Int.MAX_VALUE
    return under * ADD_RESOURCE + over * REMOVE_RESOURCE
}

fun scanMap(row: Int, column: Int, sc: Scanner): Array<Array<Int>> {
    val result: Array<Array<Int>> = Array(row) { Array(column) { 0 } }
    for (i: Int in 0 until row) {
        val nextLine = sc.nextLine()
        val split = nextLine.split(" ")
        for (j: Int in 0 until column) {
            result[i][j] = split[j].toInt()
        }
    }
    return result
}
