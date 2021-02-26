.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80066270
/* 41670 80066270 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 41674 80066274 AFBF0024 */  sw        $ra, 0x24($sp)
/* 41678 80066278 AFB40020 */  sw        $s4, 0x20($sp)
/* 4167C 8006627C AFB3001C */  sw        $s3, 0x1c($sp)
/* 41680 80066280 AFB20018 */  sw        $s2, 0x18($sp)
/* 41684 80066284 AFB10014 */  sw        $s1, 0x14($sp)
/* 41688 80066288 0C01ACD0 */  jal       func_8006B340
/* 4168C 8006628C AFB00010 */   sw       $s0, 0x10($sp)
/* 41690 80066290 0C019674 */  jal       func_800659D0
/* 41694 80066294 0040A021 */   addu     $s4, $v0, $zero
/* 41698 80066298 3C03800A */  lui       $v1, %hi(D_8009A5A8)
/* 4169C 8006629C 8C63A5A8 */  lw        $v1, %lo(D_8009A5A8)($v1)
/* 416A0 800662A0 3C12800A */  lui       $s2, %hi(D_8009A5E8)
/* 416A4 800662A4 8E52A5E8 */  lw        $s2, %lo(D_8009A5E8)($s2)
/* 416A8 800662A8 3C13800A */  lui       $s3, %hi(D_8009A5EC)
/* 416AC 800662AC 8E73A5EC */  lw        $s3, %lo(D_8009A5EC)($s3)
/* 416B0 800662B0 02802021 */  addu      $a0, $s4, $zero
/* 416B4 800662B4 0C01ACEC */  jal       func_8006B3B0
/* 416B8 800662B8 00438023 */   subu     $s0, $v0, $v1
/* 416BC 800662BC 02008821 */  addu      $s1, $s0, $zero
/* 416C0 800662C0 00008021 */  addu      $s0, $zero, $zero
/* 416C4 800662C4 02711821 */  addu      $v1, $s3, $s1
/* 416C8 800662C8 0071202B */  sltu      $a0, $v1, $s1
/* 416CC 800662CC 02501021 */  addu      $v0, $s2, $s0
/* 416D0 800662D0 00441021 */  addu      $v0, $v0, $a0
/* 416D4 800662D4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 416D8 800662D8 8FB40020 */  lw        $s4, 0x20($sp)
/* 416DC 800662DC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 416E0 800662E0 8FB20018 */  lw        $s2, 0x18($sp)
/* 416E4 800662E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 416E8 800662E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 416EC 800662EC 03E00008 */  jr        $ra
/* 416F0 800662F0 27BD0028 */   addiu    $sp, $sp, 0x28
/* 416F4 800662F4 00000000 */  nop
/* 416F8 800662F8 00000000 */  nop
/* 416FC 800662FC 00000000 */  nop
