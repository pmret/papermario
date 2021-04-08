.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flo_08_UnkFunc17
/* CAED5C 8024001C 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* CAED60 80240020 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* CAED64 80240024 8C430000 */  lw        $v1, ($v0)
/* CAED68 80240028 2404FFBF */  addiu     $a0, $zero, -0x41
/* CAED6C 8024002C 00641824 */  and       $v1, $v1, $a0
/* CAED70 80240030 AC430000 */  sw        $v1, ($v0)
/* CAED74 80240034 03E00008 */  jr        $ra
/* CAED78 80240038 24020002 */   addiu    $v0, $zero, 2
