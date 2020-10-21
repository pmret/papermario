.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CE8_B076E8
/* B076E8 80240CE8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B076EC 80240CEC 3C028011 */  lui       $v0, %hi(gPlayerData)
/* B076F0 80240CF0 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* B076F4 80240CF4 AFBF0010 */  sw        $ra, 0x10($sp)
/* B076F8 80240CF8 90450003 */  lbu       $a1, 3($v0)
/* B076FC 80240CFC 90460006 */  lbu       $a2, 6($v0)
/* B07700 80240D00 8044028E */  lb        $a0, 0x28e($v0)
/* B07704 80240D04 24030002 */  addiu     $v1, $zero, 2
/* B07708 80240D08 A0430292 */  sb        $v1, 0x292($v0)
/* B0770C 80240D0C 00042200 */  sll       $a0, $a0, 8
/* B07710 80240D10 A0450002 */  sb        $a1, 2($v0)
/* B07714 80240D14 A0460005 */  sb        $a2, 5($v0)
/* B07718 80240D18 0C03A6DB */  jal       sync_status_menu
/* B0771C 80240D1C A4440290 */   sh       $a0, 0x290($v0)
/* B07720 80240D20 8FBF0010 */  lw        $ra, 0x10($sp)
/* B07724 80240D24 24020002 */  addiu     $v0, $zero, 2
/* B07728 80240D28 03E00008 */  jr        $ra
/* B0772C 80240D2C 27BD0018 */   addiu    $sp, $sp, 0x18
