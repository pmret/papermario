.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80266684
/* 194F64 80266684 0000282D */  daddu     $a1, $zero, $zero
/* 194F68 80266688 24060005 */  addiu     $a2, $zero, 5
/* 194F6C 8026668C 3C038029 */  lui       $v1, 0x8029
/* 194F70 80266690 246338AC */  addiu     $v1, $v1, 0x38ac
/* 194F74 80266694 3C048029 */  lui       $a0, 0x8029
/* 194F78 80266698 2484390C */  addiu     $a0, $a0, 0x390c
.L8026669C:
/* 194F7C 8026669C 8C620000 */  lw        $v0, ($v1)
/* 194F80 802666A0 5040000A */  beql      $v0, $zero, .L802666CC
/* 194F84 802666A4 24630004 */   addiu    $v1, $v1, 4
/* 194F88 802666A8 8C820000 */  lw        $v0, ($a0)
/* 194F8C 802666AC 2442FFFF */  addiu     $v0, $v0, -1
/* 194F90 802666B0 14400005 */  bnez      $v0, .L802666C8
/* 194F94 802666B4 AC820000 */   sw       $v0, ($a0)
/* 194F98 802666B8 8C620000 */  lw        $v0, ($v1)
/* 194F9C 802666BC 8C42000C */  lw        $v0, 0xc($v0)
/* 194FA0 802666C0 AC460030 */  sw        $a2, 0x30($v0)
/* 194FA4 802666C4 AC600000 */  sw        $zero, ($v1)
.L802666C8:
/* 194FA8 802666C8 24630004 */  addiu     $v1, $v1, 4
.L802666CC:
/* 194FAC 802666CC 24A50001 */  addiu     $a1, $a1, 1
/* 194FB0 802666D0 28A20018 */  slti      $v0, $a1, 0x18
/* 194FB4 802666D4 1440FFF1 */  bnez      $v0, .L8026669C
/* 194FB8 802666D8 24840004 */   addiu    $a0, $a0, 4
/* 194FBC 802666DC 03E00008 */  jr        $ra
/* 194FC0 802666E0 00000000 */   nop      
