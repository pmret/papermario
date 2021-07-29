.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025E14C
/* 18CA2C 8025E14C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 18CA30 8025E150 24020078 */  addiu     $v0, $zero, 0x78
/* 18CA34 8025E154 44801000 */  mtc1      $zero, $f2
/* 18CA38 8025E158 3C013F80 */  lui       $at, 0x3f80
/* 18CA3C 8025E15C 44810000 */  mtc1      $at, $f0
/* 18CA40 8025E160 3C0642C8 */  lui       $a2, 0x42c8
/* 18CA44 8025E164 44051000 */  mfc1      $a1, $f2
/* 18CA48 8025E168 24040003 */  addiu     $a0, $zero, 3
/* 18CA4C 8025E16C AFBF0018 */  sw        $ra, 0x18($sp)
/* 18CA50 8025E170 AFA20014 */  sw        $v0, 0x14($sp)
/* 18CA54 8025E174 E7A00010 */  swc1      $f0, 0x10($sp)
/* 18CA58 8025E178 0C01C484 */  jal       playFX_44
/* 18CA5C 8025E17C 00A0382D */   daddu    $a3, $a1, $zero
/* 18CA60 8025E180 8FBF0018 */  lw        $ra, 0x18($sp)
/* 18CA64 8025E184 24020002 */  addiu     $v0, $zero, 2
/* 18CA68 8025E188 03E00008 */  jr        $ra
/* 18CA6C 8025E18C 27BD0020 */   addiu    $sp, $sp, 0x20
