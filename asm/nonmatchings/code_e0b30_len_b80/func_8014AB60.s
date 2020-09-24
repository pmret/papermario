.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014AB60
/* E1260 8014AB60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E1264 8014AB64 3C028016 */  lui       $v0, 0x8016
/* E1268 8014AB68 24429AF0 */  addiu     $v0, $v0, -0x6510
/* E126C 8014AB6C 00041840 */  sll       $v1, $a0, 1
/* E1270 8014AB70 00641821 */  addu      $v1, $v1, $a0
/* E1274 8014AB74 00031900 */  sll       $v1, $v1, 4
/* E1278 8014AB78 00621821 */  addu      $v1, $v1, $v0
/* E127C 8014AB7C AFBF0010 */  sw        $ra, 0x10($sp)
/* E1280 8014AB80 94620000 */  lhu       $v0, ($v1)
/* E1284 8014AB84 30420001 */  andi      $v0, $v0, 1
/* E1288 8014AB88 10400006 */  beqz      $v0, .L8014ABA4
/* E128C 8014AB8C 00052C00 */   sll      $a1, $a1, 0x10
/* E1290 8014AB90 8C640018 */  lw        $a0, 0x18($v1)
/* E1294 8014AB94 0C015792 */  jal       func_80055E48
/* E1298 8014AB98 00052C03 */   sra      $a1, $a1, 0x10
/* E129C 8014AB9C 08052AEA */  j         .L8014ABA8
/* E12A0 8014ABA0 00000000 */   nop      
.L8014ABA4:
/* E12A4 8014ABA4 0000102D */  daddu     $v0, $zero, $zero
.L8014ABA8:
/* E12A8 8014ABA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* E12AC 8014ABAC 03E00008 */  jr        $ra
/* E12B0 8014ABB0 27BD0018 */   addiu    $sp, $sp, 0x18
