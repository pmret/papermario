.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C5C_9D9C7C
/* 9D9C7C 80242C5C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D9C80 80242C60 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9D9C84 80242C64 8C82000C */  lw        $v0, 0xc($a0)
/* 9D9C88 80242C68 0C0B1EAF */  jal       evt_get_variable
/* 9D9C8C 80242C6C 8C450000 */   lw       $a1, ($v0)
/* 9D9C90 80242C70 0040182D */  daddu     $v1, $v0, $zero
/* 9D9C94 80242C74 10600012 */  beqz      $v1, .L80242CC0
/* 9D9C98 80242C78 0000202D */   daddu    $a0, $zero, $zero
/* 9D9C9C 80242C7C 8C620000 */  lw        $v0, ($v1)
/* 9D9CA0 80242C80 5040000A */  beql      $v0, $zero, .L80242CAC
/* 9D9CA4 80242C84 00041080 */   sll      $v0, $a0, 2
/* 9D9CA8 80242C88 3C058025 */  lui       $a1, %hi(D_802549D0)
/* 9D9CAC 80242C8C 24A549D0 */  addiu     $a1, $a1, %lo(D_802549D0)
.L80242C90:
/* 9D9CB0 80242C90 24630004 */  addiu     $v1, $v1, 4
/* 9D9CB4 80242C94 24840001 */  addiu     $a0, $a0, 1
/* 9D9CB8 80242C98 ACA20000 */  sw        $v0, ($a1)
/* 9D9CBC 80242C9C 8C620000 */  lw        $v0, ($v1)
/* 9D9CC0 80242CA0 1440FFFB */  bnez      $v0, .L80242C90
/* 9D9CC4 80242CA4 24A50004 */   addiu    $a1, $a1, 4
/* 9D9CC8 80242CA8 00041080 */  sll       $v0, $a0, 2
.L80242CAC:
/* 9D9CCC 80242CAC 3C018025 */  lui       $at, %hi(D_802549D0)
/* 9D9CD0 80242CB0 00220821 */  addu      $at, $at, $v0
/* 9D9CD4 80242CB4 AC2049D0 */  sw        $zero, %lo(D_802549D0)($at)
/* 9D9CD8 80242CB8 08090B3A */  j         .L80242CE8
/* 9D9CDC 80242CBC 00000000 */   nop
.L80242CC0:
/* 9D9CE0 80242CC0 3C038025 */  lui       $v1, %hi(D_802549D0)
/* 9D9CE4 80242CC4 246349D0 */  addiu     $v1, $v1, %lo(D_802549D0)
/* 9D9CE8 80242CC8 0060282D */  daddu     $a1, $v1, $zero
.L80242CCC:
/* 9D9CEC 80242CCC 24820010 */  addiu     $v0, $a0, 0x10
/* 9D9CF0 80242CD0 AC620000 */  sw        $v0, ($v1)
/* 9D9CF4 80242CD4 24630004 */  addiu     $v1, $v1, 4
/* 9D9CF8 80242CD8 24840001 */  addiu     $a0, $a0, 1
/* 9D9CFC 80242CDC 28820070 */  slti      $v0, $a0, 0x70
/* 9D9D00 80242CE0 1440FFFA */  bnez      $v0, .L80242CCC
/* 9D9D04 80242CE4 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80242CE8:
/* 9D9D08 80242CE8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9D9D0C 80242CEC 24020002 */  addiu     $v0, $zero, 2
/* 9D9D10 80242CF0 03E00008 */  jr        $ra
/* 9D9D14 80242CF4 27BD0018 */   addiu    $sp, $sp, 0x18
