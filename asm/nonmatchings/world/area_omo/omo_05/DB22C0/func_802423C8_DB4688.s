.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802423C8_DB4688
/* DB4688 802423C8 2404005A */  addiu     $a0, $zero, 0x5a
/* DB468C 802423CC 3C038024 */  lui       $v1, %hi(D_80245928)
/* DB4690 802423D0 24635928 */  addiu     $v1, $v1, %lo(D_80245928)
/* DB4694 802423D4 240200DA */  addiu     $v0, $zero, 0xda
.L802423D8:
/* DB4698 802423D8 AC620000 */  sw        $v0, ($v1)
/* DB469C 802423DC 2463FFFC */  addiu     $v1, $v1, -4
/* DB46A0 802423E0 2484FFFF */  addiu     $a0, $a0, -1
/* DB46A4 802423E4 0481FFFC */  bgez      $a0, .L802423D8
/* DB46A8 802423E8 2442FFFF */   addiu    $v0, $v0, -1
/* DB46AC 802423EC 3C018024 */  lui       $at, %hi(D_8024592C)
/* DB46B0 802423F0 AC20592C */  sw        $zero, %lo(D_8024592C)($at)
/* DB46B4 802423F4 03E00008 */  jr        $ra
/* DB46B8 802423F8 24020002 */   addiu    $v0, $zero, 2
/* DB46BC 802423FC 00000000 */  nop
