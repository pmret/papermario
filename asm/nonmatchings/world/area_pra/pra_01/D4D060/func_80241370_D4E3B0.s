.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241370_D4E3B0
/* D4E3B0 80241370 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D4E3B4 80241374 AFBF0010 */  sw        $ra, 0x10($sp)
/* D4E3B8 80241378 0C03A876 */  jal       set_max_SP
/* D4E3BC 8024137C 24040007 */   addiu    $a0, $zero, 7
/* D4E3C0 80241380 3C028011 */  lui       $v0, %hi(gPlayerData)
/* D4E3C4 80241384 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* D4E3C8 80241388 90430003 */  lbu       $v1, 3($v0)
/* D4E3CC 8024138C 90440006 */  lbu       $a0, 6($v0)
/* D4E3D0 80241390 A0430002 */  sb        $v1, 2($v0)
/* D4E3D4 80241394 0C03A6DB */  jal       sync_status_menu
/* D4E3D8 80241398 A0440005 */   sb       $a0, 5($v0)
/* D4E3DC 8024139C 8FBF0010 */  lw        $ra, 0x10($sp)
/* D4E3E0 802413A0 24020002 */  addiu     $v0, $zero, 2
/* D4E3E4 802413A4 03E00008 */  jr        $ra
/* D4E3E8 802413A8 27BD0018 */   addiu    $sp, $sp, 0x18
/* D4E3EC 802413AC 00000000 */  nop       
