.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel Disable8bitMario
/* F7538 802D2B88 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F753C 802D2B8C AFBF0018 */  sw        $ra, 0x18($sp)
/* F7540 802D2B90 AFB10014 */  sw        $s1, 0x14($sp)
/* F7544 802D2B94 AFB00010 */  sw        $s0, 0x10($sp)
/* F7548 802D2B98 8C82000C */  lw        $v0, 0xc($a0)
/* F754C 802D2B9C 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* F7550 802D2BA0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* F7554 802D2BA4 8C450000 */  lw        $a1, ($v0)
/* F7558 802D2BA8 0C0B1EAF */  jal       get_variable
/* F755C 802D2BAC 0200882D */   daddu    $s1, $s0, $zero
/* F7560 802D2BB0 10400009 */  beqz      $v0, .L802D2BD8
/* F7564 802D2BB4 24020025 */   addiu    $v0, $zero, 0x25
/* F7568 802D2BB8 A60200B0 */  sh        $v0, 0xb0($s0)
/* F756C 802D2BBC 2402001A */  addiu     $v0, $zero, 0x1a
/* F7570 802D2BC0 A60200B2 */  sh        $v0, 0xb2($s0)
/* F7574 802D2BC4 8E020004 */  lw        $v0, 4($s0)
/* F7578 802D2BC8 2403BFFF */  addiu     $v1, $zero, -0x4001
/* F757C 802D2BCC 00431024 */  and       $v0, $v0, $v1
/* F7580 802D2BD0 080B4AFF */  j         .L802D2BFC
/* F7584 802D2BD4 AE020004 */   sw       $v0, 4($s0)
.L802D2BD8:
/* F7588 802D2BD8 3C040004 */  lui       $a0, 4
/* F758C 802D2BDC 34844004 */  ori       $a0, $a0, 0x4004
/* F7590 802D2BE0 24020013 */  addiu     $v0, $zero, 0x13
/* F7594 802D2BE4 A62200B0 */  sh        $v0, 0xb0($s1)
/* F7598 802D2BE8 8E220004 */  lw        $v0, 4($s1)
/* F759C 802D2BEC 2403001A */  addiu     $v1, $zero, 0x1a
/* F75A0 802D2BF0 A62300B2 */  sh        $v1, 0xb2($s1)
/* F75A4 802D2BF4 00441025 */  or        $v0, $v0, $a0
/* F75A8 802D2BF8 AE220004 */  sw        $v0, 4($s1)
.L802D2BFC:
/* F75AC 802D2BFC 8FBF0018 */  lw        $ra, 0x18($sp)
/* F75B0 802D2C00 8FB10014 */  lw        $s1, 0x14($sp)
/* F75B4 802D2C04 8FB00010 */  lw        $s0, 0x10($sp)
/* F75B8 802D2C08 24020002 */  addiu     $v0, $zero, 2
/* F75BC 802D2C0C 03E00008 */  jr        $ra
/* F75C0 802D2C10 27BD0020 */   addiu    $sp, $sp, 0x20
