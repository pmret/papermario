.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A920
/* D1020 8013A920 00041940 */  sll       $v1, $a0, 5
/* D1024 8013A924 00641823 */  subu      $v1, $v1, $a0
/* D1028 8013A928 3C028015 */  lui       $v0, %hi(D_80156954)
/* D102C 8013A92C 8C426954 */  lw        $v0, %lo(D_80156954)($v0)
/* D1030 8013A930 00031880 */  sll       $v1, $v1, 2
/* D1034 8013A934 03E00008 */  jr        $ra
/* D1038 8013A938 00431021 */   addu     $v0, $v0, $v1
