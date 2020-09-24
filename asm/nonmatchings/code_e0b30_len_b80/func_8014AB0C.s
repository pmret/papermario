.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014AB0C
/* E120C 8014AB0C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E1210 8014AB10 3C028016 */  lui       $v0, 0x8016
/* E1214 8014AB14 24429AF0 */  addiu     $v0, $v0, -0x6510
/* E1218 8014AB18 00041840 */  sll       $v1, $a0, 1
/* E121C 8014AB1C 00641821 */  addu      $v1, $v1, $a0
/* E1220 8014AB20 00031900 */  sll       $v1, $v1, 4
/* E1224 8014AB24 00621821 */  addu      $v1, $v1, $v0
/* E1228 8014AB28 AFBF0010 */  sw        $ra, 0x10($sp)
/* E122C 8014AB2C 94620000 */  lhu       $v0, ($v1)
/* E1230 8014AB30 30420001 */  andi      $v0, $v0, 1
/* E1234 8014AB34 10400006 */  beqz      $v0, .L8014AB50
/* E1238 8014AB38 00052C00 */   sll      $a1, $a1, 0x10
/* E123C 8014AB3C 8C640018 */  lw        $a0, 0x18($v1)
/* E1240 8014AB40 0C015777 */  jal       func_80055DDC
/* E1244 8014AB44 00052C03 */   sra      $a1, $a1, 0x10
/* E1248 8014AB48 08052AD5 */  j         .L8014AB54
/* E124C 8014AB4C 00000000 */   nop      
.L8014AB50:
/* E1250 8014AB50 0000102D */  daddu     $v0, $zero, $zero
.L8014AB54:
/* E1254 8014AB54 8FBF0010 */  lw        $ra, 0x10($sp)
/* E1258 8014AB58 03E00008 */  jr        $ra
/* E125C 8014AB5C 27BD0018 */   addiu    $sp, $sp, 0x18
