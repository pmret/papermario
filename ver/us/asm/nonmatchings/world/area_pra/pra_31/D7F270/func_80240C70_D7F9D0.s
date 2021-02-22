.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C70_D7F9D0
/* D7F9D0 80240C70 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D7F9D4 80240C74 AFB10014 */  sw        $s1, 0x14($sp)
/* D7F9D8 80240C78 0080882D */  daddu     $s1, $a0, $zero
/* D7F9DC 80240C7C AFBF0018 */  sw        $ra, 0x18($sp)
/* D7F9E0 80240C80 AFB00010 */  sw        $s0, 0x10($sp)
/* D7F9E4 80240C84 8E22000C */  lw        $v0, 0xc($s1)
/* D7F9E8 80240C88 0C0B1EAF */  jal       get_variable
/* D7F9EC 80240C8C 8C450000 */   lw       $a1, ($v0)
/* D7F9F0 80240C90 0220202D */  daddu     $a0, $s1, $zero
/* D7F9F4 80240C94 3C05FD05 */  lui       $a1, 0xfd05
/* D7F9F8 80240C98 34A50F80 */  ori       $a1, $a1, 0xf80
/* D7F9FC 80240C9C 0C0B1EAF */  jal       get_variable
/* D7FA00 80240CA0 0040802D */   daddu    $s0, $v0, $zero
/* D7FA04 80240CA4 00101840 */  sll       $v1, $s0, 1
/* D7FA08 80240CA8 00701821 */  addu      $v1, $v1, $s0
/* D7FA0C 80240CAC 000318C0 */  sll       $v1, $v1, 3
/* D7FA10 80240CB0 00431021 */  addu      $v0, $v0, $v1
/* D7FA14 80240CB4 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D7FA18 80240CB8 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D7FA1C 80240CBC C4400014 */  lwc1      $f0, 0x14($v0)
/* D7FA20 80240CC0 2402005A */  addiu     $v0, $zero, 0x5a
/* D7FA24 80240CC4 4600010D */  trunc.w.s $f4, $f0
/* D7FA28 80240CC8 44032000 */  mfc1      $v1, $f4
/* D7FA2C 80240CCC 00000000 */  nop
/* D7FA30 80240CD0 10620015 */  beq       $v1, $v0, .L80240D28
/* D7FA34 80240CD4 2862005B */   slti     $v0, $v1, 0x5b
/* D7FA38 80240CD8 10400005 */  beqz      $v0, .L80240CF0
/* D7FA3C 80240CDC 240200B4 */   addiu    $v0, $zero, 0xb4
/* D7FA40 80240CE0 10600009 */  beqz      $v1, .L80240D08
/* D7FA44 80240CE4 00000000 */   nop
/* D7FA48 80240CE8 08090369 */  j         .L80240DA4
/* D7FA4C 80240CEC 00000000 */   nop
.L80240CF0:
/* D7FA50 80240CF0 10620015 */  beq       $v1, $v0, .L80240D48
/* D7FA54 80240CF4 2402010E */   addiu    $v0, $zero, 0x10e
/* D7FA58 80240CF8 10620020 */  beq       $v1, $v0, .L80240D7C
/* D7FA5C 80240CFC 00000000 */   nop
/* D7FA60 80240D00 08090369 */  j         .L80240DA4
/* D7FA64 80240D04 00000000 */   nop
.L80240D08:
/* D7FA68 80240D08 C6000030 */  lwc1      $f0, 0x30($s0)
/* D7FA6C 80240D0C 4600010D */  trunc.w.s $f4, $f0
/* D7FA70 80240D10 E6240090 */  swc1      $f4, 0x90($s1)
/* D7FA74 80240D14 C6020030 */  lwc1      $f2, 0x30($s0)
/* D7FA78 80240D18 3C014248 */  lui       $at, 0x4248
/* D7FA7C 80240D1C 44810000 */  mtc1      $at, $f0
/* D7FA80 80240D20 0809035A */  j         .L80240D68
/* D7FA84 80240D24 46001080 */   add.s    $f2, $f2, $f0
.L80240D28:
/* D7FA88 80240D28 C6000028 */  lwc1      $f0, 0x28($s0)
/* D7FA8C 80240D2C 3C014248 */  lui       $at, 0x4248
/* D7FA90 80240D30 44811000 */  mtc1      $at, $f2
/* D7FA94 80240D34 4600010D */  trunc.w.s $f4, $f0
/* D7FA98 80240D38 E6240090 */  swc1      $f4, 0x90($s1)
/* D7FA9C 80240D3C C6000028 */  lwc1      $f0, 0x28($s0)
/* D7FAA0 80240D40 08090366 */  j         .L80240D98
/* D7FAA4 80240D44 46020000 */   add.s    $f0, $f0, $f2
.L80240D48:
/* D7FAA8 80240D48 C6000030 */  lwc1      $f0, 0x30($s0)
/* D7FAAC 80240D4C 4600010D */  trunc.w.s $f4, $f0
/* D7FAB0 80240D50 E6240090 */  swc1      $f4, 0x90($s1)
/* D7FAB4 80240D54 C6020030 */  lwc1      $f2, 0x30($s0)
/* D7FAB8 80240D58 3C014248 */  lui       $at, 0x4248
/* D7FABC 80240D5C 44810000 */  mtc1      $at, $f0
/* D7FAC0 80240D60 00000000 */  nop
/* D7FAC4 80240D64 46001081 */  sub.s     $f2, $f2, $f0
.L80240D68:
/* D7FAC8 80240D68 24020001 */  addiu     $v0, $zero, 1
/* D7FACC 80240D6C AE220098 */  sw        $v0, 0x98($s1)
/* D7FAD0 80240D70 4600110D */  trunc.w.s $f4, $f2
/* D7FAD4 80240D74 08090369 */  j         .L80240DA4
/* D7FAD8 80240D78 E6240094 */   swc1     $f4, 0x94($s1)
.L80240D7C:
/* D7FADC 80240D7C C6000028 */  lwc1      $f0, 0x28($s0)
/* D7FAE0 80240D80 3C014248 */  lui       $at, 0x4248
/* D7FAE4 80240D84 44811000 */  mtc1      $at, $f2
/* D7FAE8 80240D88 4600010D */  trunc.w.s $f4, $f0
/* D7FAEC 80240D8C E6240090 */  swc1      $f4, 0x90($s1)
/* D7FAF0 80240D90 C6000028 */  lwc1      $f0, 0x28($s0)
/* D7FAF4 80240D94 46020001 */  sub.s     $f0, $f0, $f2
.L80240D98:
/* D7FAF8 80240D98 AE200098 */  sw        $zero, 0x98($s1)
/* D7FAFC 80240D9C 4600010D */  trunc.w.s $f4, $f0
/* D7FB00 80240DA0 E6240094 */  swc1      $f4, 0x94($s1)
.L80240DA4:
/* D7FB04 80240DA4 8FBF0018 */  lw        $ra, 0x18($sp)
/* D7FB08 80240DA8 8FB10014 */  lw        $s1, 0x14($sp)
/* D7FB0C 80240DAC 8FB00010 */  lw        $s0, 0x10($sp)
/* D7FB10 80240DB0 24020002 */  addiu     $v0, $zero, 2
/* D7FB14 80240DB4 03E00008 */  jr        $ra
/* D7FB18 80240DB8 27BD0020 */   addiu    $sp, $sp, 0x20
