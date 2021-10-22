.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_78_update
/* 3982F8 E009C108 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3982FC E009C10C AFBF0010 */  sw        $ra, 0x10($sp)
/* 398300 E009C110 8C830000 */  lw        $v1, ($a0)
/* 398304 E009C114 8C85000C */  lw        $a1, 0xc($a0)
/* 398308 E009C118 30620010 */  andi      $v0, $v1, 0x10
/* 39830C E009C11C 10400005 */  beqz      $v0, .LE009C134
/* 398310 E009C120 2402FFEF */   addiu    $v0, $zero, -0x11
/* 398314 E009C124 00621024 */  and       $v0, $v1, $v0
/* 398318 E009C128 AC820000 */  sw        $v0, ($a0)
/* 39831C E009C12C 2402001E */  addiu     $v0, $zero, 0x1e
/* 398320 E009C130 ACA20004 */  sw        $v0, 4($a1)
.LE009C134:
/* 398324 E009C134 8CA30004 */  lw        $v1, 4($a1)
/* 398328 E009C138 28620064 */  slti      $v0, $v1, 0x64
/* 39832C E009C13C 10400002 */  beqz      $v0, .LE009C148
/* 398330 E009C140 2462FFFF */   addiu    $v0, $v1, -1
/* 398334 E009C144 ACA20004 */  sw        $v0, 4($a1)
.LE009C148:
/* 398338 E009C148 8CA20008 */  lw        $v0, 8($a1)
/* 39833C E009C14C 8CA60004 */  lw        $a2, 4($a1)
/* 398340 E009C150 24430001 */  addiu     $v1, $v0, 1
/* 398344 E009C154 04C10005 */  bgez      $a2, .LE009C16C
/* 398348 E009C158 ACA30008 */   sw       $v1, 8($a1)
/* 39834C E009C15C 0C080128 */  jal       shim_remove_effect
/* 398350 E009C160 00000000 */   nop
/* 398354 E009C164 08027074 */  j         .LE009C1D0
/* 398358 E009C168 00000000 */   nop
.LE009C16C:
/* 39835C E009C16C 28C20010 */  slti      $v0, $a2, 0x10
/* 398360 E009C170 10400002 */  beqz      $v0, .LE009C17C
/* 398364 E009C174 00061100 */   sll      $v0, $a2, 4
/* 398368 E009C178 ACA20018 */  sw        $v0, 0x18($a1)
.LE009C17C:
/* 39836C E009C17C 8CA20034 */  lw        $v0, 0x34($a1)
/* 398370 E009C180 14400002 */  bnez      $v0, .LE009C18C
/* 398374 E009C184 0062001A */   div      $zero, $v1, $v0
/* 398378 E009C188 0007000D */  break     7
.LE009C18C:
/* 39837C E009C18C 2401FFFF */   addiu    $at, $zero, -1
/* 398380 E009C190 14410004 */  bne       $v0, $at, .LE009C1A4
/* 398384 E009C194 3C018000 */   lui      $at, 0x8000
/* 398388 E009C198 14610002 */  bne       $v1, $at, .LE009C1A4
/* 39838C E009C19C 00000000 */   nop
/* 398390 E009C1A0 0006000D */  break     6
.LE009C1A4:
/* 398394 E009C1A4 00001810 */   mfhi     $v1
/* 398398 E009C1A8 14600009 */  bnez      $v1, .LE009C1D0
/* 39839C E009C1AC 00000000 */   nop
/* 3983A0 E009C1B0 8CA2002C */  lw        $v0, 0x2c($a1)
/* 3983A4 E009C1B4 8CA30030 */  lw        $v1, 0x30($a1)
/* 3983A8 E009C1B8 00431821 */  addu      $v1, $v0, $v1
/* 3983AC E009C1BC 28620401 */  slti      $v0, $v1, 0x401
/* 3983B0 E009C1C0 14400003 */  bnez      $v0, .LE009C1D0
/* 3983B4 E009C1C4 ACA3002C */   sw       $v1, 0x2c($a1)
/* 3983B8 E009C1C8 2462FC00 */  addiu     $v0, $v1, -0x400
/* 3983BC E009C1CC ACA2002C */  sw        $v0, 0x2c($a1)
.LE009C1D0:
/* 3983C0 E009C1D0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3983C4 E009C1D4 03E00008 */  jr        $ra
/* 3983C8 E009C1D8 27BD0018 */   addiu    $sp, $sp, 0x18
