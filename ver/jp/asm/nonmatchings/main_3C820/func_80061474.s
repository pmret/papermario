.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061474
/* 3C874 80061474 3C028009 */  lui       $v0, %hi(D_80093D70)
/* 3C878 80061478 8C423D70 */  lw        $v0, %lo(D_80093D70)($v0)
/* 3C87C 8006147C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3C880 80061480 1440000F */  bnez      $v0, .L800614C0
/* 3C884 80061484 AFBF0018 */   sw       $ra, 0x18($sp)
/* 3C888 80061488 24020001 */  addiu     $v0, $zero, 1
/* 3C88C 8006148C 3C018009 */  lui       $at, %hi(D_80093D70)
/* 3C890 80061490 AC223D70 */  sw        $v0, %lo(D_80093D70)($at)
/* 3C894 80061494 3C04800B */  lui       $a0, %hi(D_800B4360)
/* 3C898 80061498 24844360 */  addiu     $a0, $a0, %lo(D_800B4360)
/* 3C89C 8006149C 3C05800B */  lui       $a1, %hi(D_800AF890)
/* 3C8A0 800614A0 24A5F890 */  addiu     $a1, $a1, %lo(D_800AF890)
/* 3C8A4 800614A4 0C019554 */  jal       func_80065550
/* 3C8A8 800614A8 24060001 */   addiu    $a2, $zero, 1
/* 3C8AC 800614AC 3C04800B */  lui       $a0, %hi(D_800B4360)
/* 3C8B0 800614B0 24844360 */  addiu     $a0, $a0, %lo(D_800B4360)
/* 3C8B4 800614B4 00002821 */  addu      $a1, $zero, $zero
/* 3C8B8 800614B8 0C0195FC */  jal       func_800657F0
/* 3C8BC 800614BC 00003021 */   addu     $a2, $zero, $zero
.L800614C0:
/* 3C8C0 800614C0 3C04800B */  lui       $a0, %hi(D_800B4360)
/* 3C8C4 800614C4 24844360 */  addiu     $a0, $a0, %lo(D_800B4360)
/* 3C8C8 800614C8 27A50010 */  addiu     $a1, $sp, 0x10
/* 3C8CC 800614CC 0C0195B0 */  jal       func_800656C0
/* 3C8D0 800614D0 24060001 */   addiu    $a2, $zero, 1
/* 3C8D4 800614D4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3C8D8 800614D8 03E00008 */  jr        $ra
/* 3C8DC 800614DC 27BD0020 */   addiu    $sp, $sp, 0x20
