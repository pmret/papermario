.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B00_B366D0
/* B366D0 80241B00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B366D4 80241B04 AFBF0010 */  sw        $ra, 0x10($sp)
/* B366D8 80241B08 8C82000C */  lw        $v0, 0xc($a0)
/* B366DC 80241B0C 0C0B1EAF */  jal       get_variable
/* B366E0 80241B10 8C450000 */   lw       $a1, ($v0)
/* B366E4 80241B14 0040182D */  daddu     $v1, $v0, $zero
/* B366E8 80241B18 10600012 */  beqz      $v1, .L80241B64
/* B366EC 80241B1C 0000202D */   daddu    $a0, $zero, $zero
/* B366F0 80241B20 8C620000 */  lw        $v0, ($v1)
/* B366F4 80241B24 5040000A */  beql      $v0, $zero, .L80241B50
/* B366F8 80241B28 00041080 */   sll      $v0, $a0, 2
/* B366FC 80241B2C 3C058025 */  lui       $a1, %hi(D_8024FD68)
/* B36700 80241B30 24A5FD68 */  addiu     $a1, $a1, %lo(D_8024FD68)
.L80241B34:
/* B36704 80241B34 24630004 */  addiu     $v1, $v1, 4
/* B36708 80241B38 24840001 */  addiu     $a0, $a0, 1
/* B3670C 80241B3C ACA20000 */  sw        $v0, ($a1)
/* B36710 80241B40 8C620000 */  lw        $v0, ($v1)
/* B36714 80241B44 1440FFFB */  bnez      $v0, .L80241B34
/* B36718 80241B48 24A50004 */   addiu    $a1, $a1, 4
/* B3671C 80241B4C 00041080 */  sll       $v0, $a0, 2
.L80241B50:
/* B36720 80241B50 3C018025 */  lui       $at, %hi(D_8024FD68)
/* B36724 80241B54 00220821 */  addu      $at, $at, $v0
/* B36728 80241B58 AC20FD68 */  sw        $zero, %lo(D_8024FD68)($at)
/* B3672C 80241B5C 080906E3 */  j         .L80241B8C
/* B36730 80241B60 00000000 */   nop
.L80241B64:
/* B36734 80241B64 3C038025 */  lui       $v1, %hi(D_8024FD68)
/* B36738 80241B68 2463FD68 */  addiu     $v1, $v1, %lo(D_8024FD68)
/* B3673C 80241B6C 0060282D */  daddu     $a1, $v1, $zero
.L80241B70:
/* B36740 80241B70 24820080 */  addiu     $v0, $a0, 0x80
/* B36744 80241B74 AC620000 */  sw        $v0, ($v1)
/* B36748 80241B78 24630004 */  addiu     $v1, $v1, 4
/* B3674C 80241B7C 24840001 */  addiu     $a0, $a0, 1
/* B36750 80241B80 2882005B */  slti      $v0, $a0, 0x5b
/* B36754 80241B84 1440FFFA */  bnez      $v0, .L80241B70
/* B36758 80241B88 ACA0016C */   sw       $zero, 0x16c($a1)
.L80241B8C:
/* B3675C 80241B8C 8FBF0010 */  lw        $ra, 0x10($sp)
/* B36760 80241B90 24020002 */  addiu     $v0, $zero, 2
/* B36764 80241B94 03E00008 */  jr        $ra
/* B36768 80241B98 27BD0018 */   addiu    $sp, $sp, 0x18
