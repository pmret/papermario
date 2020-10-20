.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411BC
/* A3A69C 802411BC 0000282D */  daddu     $a1, $zero, $zero
/* A3A6A0 802411C0 3C038011 */  lui       $v1, %hi(gPlayerData)
/* A3A6A4 802411C4 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
.L802411C8:
/* A3A6A8 802411C8 846200B4 */  lh        $v0, 0xb4($v1)
/* A3A6AC 802411CC 14440003 */  bne       $v0, $a0, .L802411DC
/* A3A6B0 802411D0 24A50001 */   addiu    $a1, $a1, 1
/* A3A6B4 802411D4 03E00008 */  jr        $ra
/* A3A6B8 802411D8 24020001 */   addiu    $v0, $zero, 1
.L802411DC:
/* A3A6BC 802411DC 28A20080 */  slti      $v0, $a1, 0x80
/* A3A6C0 802411E0 1440FFF9 */  bnez      $v0, .L802411C8
/* A3A6C4 802411E4 24630002 */   addiu    $v1, $v1, 2
/* A3A6C8 802411E8 03E00008 */  jr        $ra
/* A3A6CC 802411EC 0000102D */   daddu    $v0, $zero, $zero
