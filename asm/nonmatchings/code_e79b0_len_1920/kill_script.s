.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kill_script
/* E88EC 802C3F3C 3C03802E */  lui       $v1, %hi(gCurrentScriptListPtr)
/* E88F0 802C3F40 8C63A890 */  lw        $v1, %lo(gCurrentScriptListPtr)($v1)
/* E88F4 802C3F44 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E88F8 802C3F48 AFB20018 */  sw        $s2, 0x18($sp)
/* E88FC 802C3F4C 0080902D */  daddu     $s2, $a0, $zero
/* E8900 802C3F50 AFB00010 */  sw        $s0, 0x10($sp)
/* E8904 802C3F54 0000802D */  daddu     $s0, $zero, $zero
/* E8908 802C3F58 AFBF001C */  sw        $ra, 0x1c($sp)
/* E890C 802C3F5C AFB10014 */  sw        $s1, 0x14($sp)
.L802C3F60:
/* E8910 802C3F60 8C620000 */  lw        $v0, ($v1)
/* E8914 802C3F64 10520006 */  beq       $v0, $s2, .L802C3F80
/* E8918 802C3F68 2A020080 */   slti     $v0, $s0, 0x80
/* E891C 802C3F6C 26100001 */  addiu     $s0, $s0, 1
/* E8920 802C3F70 2A020080 */  slti      $v0, $s0, 0x80
/* E8924 802C3F74 1440FFFA */  bnez      $v0, .L802C3F60
/* E8928 802C3F78 24630004 */   addiu    $v1, $v1, 4
/* E892C 802C3F7C 2A020080 */  slti      $v0, $s0, 0x80
.L802C3F80:
/* E8930 802C3F80 10400044 */  beqz      $v0, .L802C4094
/* E8934 802C3F84 00000000 */   nop      
/* E8938 802C3F88 8E440068 */  lw        $a0, 0x68($s2)
/* E893C 802C3F8C 10800003 */  beqz      $a0, .L802C3F9C
/* E8940 802C3F90 0000882D */   daddu    $s1, $zero, $zero
/* E8944 802C3F94 0C0B0FCF */  jal       kill_script
/* E8948 802C3F98 00000000 */   nop      
.L802C3F9C:
/* E894C 802C3F9C 3C03802E */  lui       $v1, %hi(gCurrentScriptListPtr)
/* E8950 802C3FA0 8C63A890 */  lw        $v1, %lo(gCurrentScriptListPtr)($v1)
/* E8954 802C3FA4 00111080 */  sll       $v0, $s1, 2
/* E8958 802C3FA8 00431021 */  addu      $v0, $v0, $v1
/* E895C 802C3FAC 8C440000 */  lw        $a0, ($v0)
/* E8960 802C3FB0 10800006 */  beqz      $a0, .L802C3FCC
/* E8964 802C3FB4 26310001 */   addiu    $s1, $s1, 1
/* E8968 802C3FB8 8C82006C */  lw        $v0, 0x6c($a0)
/* E896C 802C3FBC 14520003 */  bne       $v0, $s2, .L802C3FCC
/* E8970 802C3FC0 00000000 */   nop      
/* E8974 802C3FC4 0C0B0FCF */  jal       kill_script
/* E8978 802C3FC8 00000000 */   nop      
.L802C3FCC:
/* E897C 802C3FCC 2A220080 */  slti      $v0, $s1, 0x80
/* E8980 802C3FD0 1440FFF2 */  bnez      $v0, .L802C3F9C
/* E8984 802C3FD4 00000000 */   nop      
/* E8988 802C3FD8 8E450064 */  lw        $a1, 0x64($s2)
/* E898C 802C3FDC 10A00018 */  beqz      $a1, .L802C4040
/* E8990 802C3FE0 0000882D */   daddu    $s1, $zero, $zero
/* E8994 802C3FE4 0240202D */  daddu     $a0, $s2, $zero
/* E8998 802C3FE8 90A20000 */  lbu       $v0, ($a1)
/* E899C 802C3FEC 00A0182D */  daddu     $v1, $a1, $zero
/* E89A0 802C3FF0 ACA00068 */  sw        $zero, 0x68($a1)
/* E89A4 802C3FF4 304200EF */  andi      $v0, $v0, 0xef
/* E89A8 802C3FF8 A0A20000 */  sb        $v0, ($a1)
.L802C3FFC:
/* E89AC 802C3FFC 8C820084 */  lw        $v0, 0x84($a0)
/* E89B0 802C4000 24840004 */  addiu     $a0, $a0, 4
/* E89B4 802C4004 26310001 */  addiu     $s1, $s1, 1
/* E89B8 802C4008 AC620084 */  sw        $v0, 0x84($v1)
/* E89BC 802C400C 2A220010 */  slti      $v0, $s1, 0x10
/* E89C0 802C4010 1440FFFA */  bnez      $v0, .L802C3FFC
/* E89C4 802C4014 24630004 */   addiu    $v1, $v1, 4
/* E89C8 802C4018 0000882D */  daddu     $s1, $zero, $zero
/* E89CC 802C401C 0240202D */  daddu     $a0, $s2, $zero
/* E89D0 802C4020 00A0182D */  daddu     $v1, $a1, $zero
.L802C4024:
/* E89D4 802C4024 8C8200C4 */  lw        $v0, 0xc4($a0)
/* E89D8 802C4028 24840004 */  addiu     $a0, $a0, 4
/* E89DC 802C402C 26310001 */  addiu     $s1, $s1, 1
/* E89E0 802C4030 AC6200C4 */  sw        $v0, 0xc4($v1)
/* E89E4 802C4034 2A220003 */  slti      $v0, $s1, 3
/* E89E8 802C4038 1440FFFA */  bnez      $v0, .L802C4024
/* E89EC 802C403C 24630004 */   addiu    $v1, $v1, 4
.L802C4040:
/* E89F0 802C4040 8E440060 */  lw        $a0, 0x60($s2)
/* E89F4 802C4044 10800004 */  beqz      $a0, .L802C4058
/* E89F8 802C4048 00000000 */   nop      
/* E89FC 802C404C 0C00AB4B */  jal       heap_free
/* E8A00 802C4050 00000000 */   nop      
/* E8A04 802C4054 AE400060 */  sw        $zero, 0x60($s2)
.L802C4058:
/* E8A08 802C4058 3C11802E */  lui       $s1, %hi(gCurrentScriptListPtr)
/* E8A0C 802C405C 2631A890 */  addiu     $s1, $s1, %lo(gCurrentScriptListPtr)
/* E8A10 802C4060 8E220000 */  lw        $v0, ($s1)
/* E8A14 802C4064 00108080 */  sll       $s0, $s0, 2
/* E8A18 802C4068 02021021 */  addu      $v0, $s0, $v0
/* E8A1C 802C406C 0C00AB4B */  jal       heap_free
/* E8A20 802C4070 8C440000 */   lw       $a0, ($v0)
/* E8A24 802C4074 3C04802E */  lui       $a0, %hi(gNumScripts)
/* E8A28 802C4078 2484A488 */  addiu     $a0, $a0, %lo(gNumScripts)
/* E8A2C 802C407C 8E230000 */  lw        $v1, ($s1)
/* E8A30 802C4080 8C820000 */  lw        $v0, ($a0)
/* E8A34 802C4084 02038021 */  addu      $s0, $s0, $v1
/* E8A38 802C4088 2442FFFF */  addiu     $v0, $v0, -1
/* E8A3C 802C408C AE000000 */  sw        $zero, ($s0)
/* E8A40 802C4090 AC820000 */  sw        $v0, ($a0)
.L802C4094:
/* E8A44 802C4094 8FBF001C */  lw        $ra, 0x1c($sp)
/* E8A48 802C4098 8FB20018 */  lw        $s2, 0x18($sp)
/* E8A4C 802C409C 8FB10014 */  lw        $s1, 0x14($sp)
/* E8A50 802C40A0 8FB00010 */  lw        $s0, 0x10($sp)
/* E8A54 802C40A4 03E00008 */  jr        $ra
/* E8A58 802C40A8 27BD0020 */   addiu    $sp, $sp, 0x20
