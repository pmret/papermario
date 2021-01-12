.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A28_ECB728
/* ECB728 80241A28 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ECB72C 80241A2C AFBF0010 */  sw        $ra, 0x10($sp)
/* ECB730 80241A30 8C82000C */  lw        $v0, 0xc($a0)
/* ECB734 80241A34 0C0B53A3 */  jal       func_802D4E8C
/* ECB738 80241A38 8C450000 */   lw       $a1, ($v0)
/* ECB73C 80241A3C 0040182D */  daddu     $v1, $v0, $zero
/* ECB740 80241A40 10600012 */  beqz      $v1, .L80241A8C
/* ECB744 80241A44 0000202D */   daddu    $a0, $zero, $zero
/* ECB748 80241A48 8C620000 */  lw        $v0, ($v1)
/* ECB74C 80241A4C 5040000A */  beql      $v0, $zero, .L80241A78
/* ECB750 80241A50 00041080 */   sll      $v0, $a0, 2
/* ECB754 80241A54 3C058024 */  lui       $a1, %hi(D_802462F0)
/* ECB758 80241A58 24A562F0 */  addiu     $a1, $a1, %lo(D_802462F0)
.L80241A5C:
/* ECB75C 80241A5C 24630004 */  addiu     $v1, $v1, 4
/* ECB760 80241A60 24840001 */  addiu     $a0, $a0, 1
/* ECB764 80241A64 ACA20000 */  sw        $v0, ($a1)
/* ECB768 80241A68 8C620000 */  lw        $v0, ($v1)
/* ECB76C 80241A6C 1440FFFB */  bnez      $v0, .L80241A5C
/* ECB770 80241A70 24A50004 */   addiu    $a1, $a1, 4
/* ECB774 80241A74 00041080 */  sll       $v0, $a0, 2
.L80241A78:
/* ECB778 80241A78 3C018024 */  lui       $at, %hi(D_802462F0)
/* ECB77C 80241A7C 00220821 */  addu      $at, $at, $v0
/* ECB780 80241A80 AC2062F0 */  sw        $zero, %lo(D_802462F0)($at)
/* ECB784 80241A84 080906AD */  j         .L80241AB4
/* ECB788 80241A88 00000000 */   nop      
.L80241A8C:
/* ECB78C 80241A8C 3C038024 */  lui       $v1, %hi(D_802462F0)
/* ECB790 80241A90 246362F0 */  addiu     $v1, $v1, %lo(D_802462F0)
/* ECB794 80241A94 0060282D */  daddu     $a1, $v1, $zero
.L80241A98:
/* ECB798 80241A98 24820080 */  addiu     $v0, $a0, 0x80
/* ECB79C 80241A9C AC620000 */  sw        $v0, ($v1)
/* ECB7A0 80241AA0 24630004 */  addiu     $v1, $v1, 4
/* ECB7A4 80241AA4 24840001 */  addiu     $a0, $a0, 1
/* ECB7A8 80241AA8 2882005B */  slti      $v0, $a0, 0x5b
/* ECB7AC 80241AAC 1440FFFA */  bnez      $v0, .L80241A98
/* ECB7B0 80241AB0 ACA0016C */   sw       $zero, 0x16c($a1)
.L80241AB4:
/* ECB7B4 80241AB4 8FBF0010 */  lw        $ra, 0x10($sp)
/* ECB7B8 80241AB8 24020002 */  addiu     $v0, $zero, 2
/* ECB7BC 80241ABC 03E00008 */  jr        $ra
/* ECB7C0 80241AC0 27BD0018 */   addiu    $sp, $sp, 0x18
