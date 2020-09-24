.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel RemoveBadge
/* FBA00 802D7050 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FBA04 802D7054 AFBF0014 */  sw        $ra, 0x14($sp)
/* FBA08 802D7058 AFB00010 */  sw        $s0, 0x10($sp)
/* FBA0C 802D705C 8C82000C */  lw        $v0, 0xc($a0)
/* FBA10 802D7060 0C0B1EAF */  jal       get_variable
/* FBA14 802D7064 8C450000 */   lw       $a1, ($v0)
/* FBA18 802D7068 0040282D */  daddu     $a1, $v0, $zero
/* FBA1C 802D706C 0000202D */  daddu     $a0, $zero, $zero
/* FBA20 802D7070 3C108011 */  lui       $s0, 0x8011
/* FBA24 802D7074 2610F290 */  addiu     $s0, $s0, -0xd70
/* FBA28 802D7078 0200182D */  daddu     $v1, $s0, $zero
.L802D707C:
/* FBA2C 802D707C 846200B4 */  lh        $v0, 0xb4($v1)
/* FBA30 802D7080 50450001 */  beql      $v0, $a1, .L802D7088
/* FBA34 802D7084 A46000B4 */   sh       $zero, 0xb4($v1)
.L802D7088:
/* FBA38 802D7088 24840001 */  addiu     $a0, $a0, 1
/* FBA3C 802D708C 28820080 */  slti      $v0, $a0, 0x80
/* FBA40 802D7090 1440FFFA */  bnez      $v0, .L802D707C
/* FBA44 802D7094 24630002 */   addiu    $v1, $v1, 2
/* FBA48 802D7098 0000202D */  daddu     $a0, $zero, $zero
/* FBA4C 802D709C 0200182D */  daddu     $v1, $s0, $zero
.L802D70A0:
/* FBA50 802D70A0 84620208 */  lh        $v0, 0x208($v1)
/* FBA54 802D70A4 50450001 */  beql      $v0, $a1, .L802D70AC
/* FBA58 802D70A8 A4600208 */   sh       $zero, 0x208($v1)
.L802D70AC:
/* FBA5C 802D70AC 24840001 */  addiu     $a0, $a0, 1
/* FBA60 802D70B0 28820040 */  slti      $v0, $a0, 0x40
/* FBA64 802D70B4 1440FFFA */  bnez      $v0, .L802D70A0
/* FBA68 802D70B8 24630002 */   addiu    $v1, $v1, 2
/* FBA6C 802D70BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* FBA70 802D70C0 8FB00010 */  lw        $s0, 0x10($sp)
/* FBA74 802D70C4 24020002 */  addiu     $v0, $zero, 2
/* FBA78 802D70C8 03E00008 */  jr        $ra
/* FBA7C 802D70CC 27BD0018 */   addiu    $sp, $sp, 0x18
