.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240384_C5AAC4
/* C5AAC4 80240384 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C5AAC8 80240388 AFBF0010 */  sw        $ra, 0x10($sp)
/* C5AACC 8024038C 8C82000C */  lw        $v0, 0xc($a0)
/* C5AAD0 80240390 3C068016 */  lui       $a2, 0x8016
/* C5AAD4 80240394 84C6A552 */  lh        $a2, -0x5aae($a2)
/* C5AAD8 80240398 0C0B2026 */  jal       set_variable
/* C5AADC 8024039C 8C450000 */   lw       $a1, ($v0)
/* C5AAE0 802403A0 8FBF0010 */  lw        $ra, 0x10($sp)
/* C5AAE4 802403A4 24020002 */  addiu     $v0, $zero, 2
/* C5AAE8 802403A8 03E00008 */  jr        $ra
/* C5AAEC 802403AC 27BD0018 */   addiu    $sp, $sp, 0x18
