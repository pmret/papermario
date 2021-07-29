.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_partners_cleanup
/* 13FCC4 8024C984 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 13FCC8 8024C988 AFB00010 */  sw        $s0, 0x10($sp)
/* 13FCCC 8024C98C 0000802D */  daddu     $s0, $zero, $zero
/* 13FCD0 8024C990 AFB10014 */  sw        $s1, 0x14($sp)
/* 13FCD4 8024C994 3C118027 */  lui       $s1, %hi(D_80270640)
/* 13FCD8 8024C998 26310640 */  addiu     $s1, $s1, %lo(D_80270640)
/* 13FCDC 8024C99C AFBF0018 */  sw        $ra, 0x18($sp)
.L8024C9A0:
/* 13FCE0 8024C9A0 8E240000 */  lw        $a0, ($s1)
/* 13FCE4 8024C9A4 26310004 */  addiu     $s1, $s1, 4
/* 13FCE8 8024C9A8 0C05123D */  jal       free_hud_element
/* 13FCEC 8024C9AC 26100001 */   addiu    $s0, $s0, 1
/* 13FCF0 8024C9B0 2A020008 */  slti      $v0, $s0, 8
/* 13FCF4 8024C9B4 1440FFFA */  bnez      $v0, .L8024C9A0
/* 13FCF8 8024C9B8 00000000 */   nop
/* 13FCFC 8024C9BC 0000802D */  daddu     $s0, $zero, $zero
/* 13FD00 8024C9C0 3C118027 */  lui       $s1, %hi(D_80270660)
/* 13FD04 8024C9C4 26310660 */  addiu     $s1, $s1, %lo(D_80270660)
.L8024C9C8:
/* 13FD08 8024C9C8 8E240000 */  lw        $a0, ($s1)
/* 13FD0C 8024C9CC 26310004 */  addiu     $s1, $s1, 4
/* 13FD10 8024C9D0 0C0B797A */  jal       spr_free_sprite
/* 13FD14 8024C9D4 26100001 */   addiu    $s0, $s0, 1
/* 13FD18 8024C9D8 2A020008 */  slti      $v0, $s0, 8
/* 13FD1C 8024C9DC 1440FFFA */  bnez      $v0, .L8024C9C8
/* 13FD20 8024C9E0 00000000 */   nop
/* 13FD24 8024C9E4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 13FD28 8024C9E8 8FB10014 */  lw        $s1, 0x14($sp)
/* 13FD2C 8024C9EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 13FD30 8024C9F0 03E00008 */  jr        $ra
/* 13FD34 8024C9F4 27BD0020 */   addiu    $sp, $sp, 0x20
/* 13FD38 8024C9F8 00000000 */  nop
/* 13FD3C 8024C9FC 00000000 */  nop
