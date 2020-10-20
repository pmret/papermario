.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BC4_D3C194
/* D3C194 80241BC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3C198 80241BC8 AFB00010 */  sw        $s0, 0x10($sp)
/* D3C19C 80241BCC 0080802D */  daddu     $s0, $a0, $zero
/* D3C1A0 80241BD0 10A00005 */  beqz      $a1, .L80241BE8
/* D3C1A4 80241BD4 AFBF0014 */   sw       $ra, 0x14($sp)
/* D3C1A8 80241BD8 AE000070 */  sw        $zero, 0x70($s0)
/* D3C1AC 80241BDC AE000074 */  sw        $zero, 0x74($s0)
/* D3C1B0 80241BE0 AE000078 */  sw        $zero, 0x78($s0)
/* D3C1B4 80241BE4 AE00007C */  sw        $zero, 0x7c($s0)
.L80241BE8:
/* D3C1B8 80241BE8 8E020070 */  lw        $v0, 0x70($s0)
/* D3C1BC 80241BEC 1440000E */  bnez      $v0, .L80241C28
/* D3C1C0 80241BF0 00000000 */   nop      
/* D3C1C4 80241BF4 8E0300A8 */  lw        $v1, 0xa8($s0)
/* D3C1C8 80241BF8 8E020088 */  lw        $v0, 0x88($s0)
/* D3C1CC 80241BFC 00621821 */  addu      $v1, $v1, $v0
/* D3C1D0 80241C00 04610004 */  bgez      $v1, .L80241C14
/* D3C1D4 80241C04 AE0300A8 */   sw       $v1, 0xa8($s0)
/* D3C1D8 80241C08 3C020002 */  lui       $v0, 2
/* D3C1DC 80241C0C 08090709 */  j         .L80241C24
/* D3C1E0 80241C10 00621021 */   addu     $v0, $v1, $v0
.L80241C14:
/* D3C1E4 80241C14 3C040002 */  lui       $a0, 2
/* D3C1E8 80241C18 0083102A */  slt       $v0, $a0, $v1
/* D3C1EC 80241C1C 10400002 */  beqz      $v0, .L80241C28
/* D3C1F0 80241C20 00641023 */   subu     $v0, $v1, $a0
.L80241C24:
/* D3C1F4 80241C24 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80241C28:
/* D3C1F8 80241C28 8E020074 */  lw        $v0, 0x74($s0)
/* D3C1FC 80241C2C 1440000E */  bnez      $v0, .L80241C68
/* D3C200 80241C30 00000000 */   nop      
/* D3C204 80241C34 8E0300AC */  lw        $v1, 0xac($s0)
/* D3C208 80241C38 8E02008C */  lw        $v0, 0x8c($s0)
/* D3C20C 80241C3C 00621821 */  addu      $v1, $v1, $v0
/* D3C210 80241C40 04610004 */  bgez      $v1, .L80241C54
/* D3C214 80241C44 AE0300AC */   sw       $v1, 0xac($s0)
/* D3C218 80241C48 3C020002 */  lui       $v0, 2
/* D3C21C 80241C4C 08090719 */  j         .L80241C64
/* D3C220 80241C50 00621021 */   addu     $v0, $v1, $v0
.L80241C54:
/* D3C224 80241C54 3C040002 */  lui       $a0, 2
/* D3C228 80241C58 0083102A */  slt       $v0, $a0, $v1
/* D3C22C 80241C5C 10400002 */  beqz      $v0, .L80241C68
/* D3C230 80241C60 00641023 */   subu     $v0, $v1, $a0
.L80241C64:
/* D3C234 80241C64 AE0200AC */  sw        $v0, 0xac($s0)
.L80241C68:
/* D3C238 80241C68 8E020078 */  lw        $v0, 0x78($s0)
/* D3C23C 80241C6C 1440000E */  bnez      $v0, .L80241CA8
/* D3C240 80241C70 00000000 */   nop      
/* D3C244 80241C74 8E0300B0 */  lw        $v1, 0xb0($s0)
/* D3C248 80241C78 8E020090 */  lw        $v0, 0x90($s0)
/* D3C24C 80241C7C 00621821 */  addu      $v1, $v1, $v0
/* D3C250 80241C80 04610004 */  bgez      $v1, .L80241C94
/* D3C254 80241C84 AE0300B0 */   sw       $v1, 0xb0($s0)
/* D3C258 80241C88 3C020002 */  lui       $v0, 2
/* D3C25C 80241C8C 08090729 */  j         .L80241CA4
/* D3C260 80241C90 00621021 */   addu     $v0, $v1, $v0
.L80241C94:
/* D3C264 80241C94 3C040002 */  lui       $a0, 2
/* D3C268 80241C98 0083102A */  slt       $v0, $a0, $v1
/* D3C26C 80241C9C 10400002 */  beqz      $v0, .L80241CA8
/* D3C270 80241CA0 00641023 */   subu     $v0, $v1, $a0
.L80241CA4:
/* D3C274 80241CA4 AE0200B0 */  sw        $v0, 0xb0($s0)
.L80241CA8:
/* D3C278 80241CA8 8E02007C */  lw        $v0, 0x7c($s0)
/* D3C27C 80241CAC 1440000E */  bnez      $v0, .L80241CE8
/* D3C280 80241CB0 00000000 */   nop      
/* D3C284 80241CB4 8E0300B4 */  lw        $v1, 0xb4($s0)
/* D3C288 80241CB8 8E020094 */  lw        $v0, 0x94($s0)
/* D3C28C 80241CBC 00621821 */  addu      $v1, $v1, $v0
/* D3C290 80241CC0 04610004 */  bgez      $v1, .L80241CD4
/* D3C294 80241CC4 AE0300B4 */   sw       $v1, 0xb4($s0)
/* D3C298 80241CC8 3C020002 */  lui       $v0, 2
/* D3C29C 80241CCC 08090739 */  j         .L80241CE4
/* D3C2A0 80241CD0 00621021 */   addu     $v0, $v1, $v0
.L80241CD4:
/* D3C2A4 80241CD4 3C040002 */  lui       $a0, 2
/* D3C2A8 80241CD8 0083102A */  slt       $v0, $a0, $v1
/* D3C2AC 80241CDC 10400002 */  beqz      $v0, .L80241CE8
/* D3C2B0 80241CE0 00641023 */   subu     $v0, $v1, $a0
.L80241CE4:
/* D3C2B4 80241CE4 AE0200B4 */  sw        $v0, 0xb4($s0)
.L80241CE8:
/* D3C2B8 80241CE8 8E040084 */  lw        $a0, 0x84($s0)
/* D3C2BC 80241CEC 0C046F07 */  jal       set_main_pan_u
/* D3C2C0 80241CF0 8E0500A8 */   lw       $a1, 0xa8($s0)
/* D3C2C4 80241CF4 8E040084 */  lw        $a0, 0x84($s0)
/* D3C2C8 80241CF8 0C046F0D */  jal       set_main_pan_v
/* D3C2CC 80241CFC 8E0500AC */   lw       $a1, 0xac($s0)
/* D3C2D0 80241D00 8E040084 */  lw        $a0, 0x84($s0)
/* D3C2D4 80241D04 0C046F13 */  jal       set_aux_pan_u
/* D3C2D8 80241D08 8E0500B0 */   lw       $a1, 0xb0($s0)
/* D3C2DC 80241D0C 8E040084 */  lw        $a0, 0x84($s0)
/* D3C2E0 80241D10 0C046F19 */  jal       set_aux_pan_v
/* D3C2E4 80241D14 8E0500B4 */   lw       $a1, 0xb4($s0)
/* D3C2E8 80241D18 8E020070 */  lw        $v0, 0x70($s0)
/* D3C2EC 80241D1C 8E030078 */  lw        $v1, 0x78($s0)
/* D3C2F0 80241D20 8E040098 */  lw        $a0, 0x98($s0)
/* D3C2F4 80241D24 24420001 */  addiu     $v0, $v0, 1
/* D3C2F8 80241D28 AE020070 */  sw        $v0, 0x70($s0)
/* D3C2FC 80241D2C 8E020074 */  lw        $v0, 0x74($s0)
/* D3C300 80241D30 24630001 */  addiu     $v1, $v1, 1
/* D3C304 80241D34 AE030078 */  sw        $v1, 0x78($s0)
/* D3C308 80241D38 8E030070 */  lw        $v1, 0x70($s0)
/* D3C30C 80241D3C 24420001 */  addiu     $v0, $v0, 1
/* D3C310 80241D40 AE020074 */  sw        $v0, 0x74($s0)
/* D3C314 80241D44 8E02007C */  lw        $v0, 0x7c($s0)
/* D3C318 80241D48 0064182A */  slt       $v1, $v1, $a0
/* D3C31C 80241D4C 24420001 */  addiu     $v0, $v0, 1
/* D3C320 80241D50 14600002 */  bnez      $v1, .L80241D5C
/* D3C324 80241D54 AE02007C */   sw       $v0, 0x7c($s0)
/* D3C328 80241D58 AE000070 */  sw        $zero, 0x70($s0)
.L80241D5C:
/* D3C32C 80241D5C 8E020074 */  lw        $v0, 0x74($s0)
/* D3C330 80241D60 8E03009C */  lw        $v1, 0x9c($s0)
/* D3C334 80241D64 0043102A */  slt       $v0, $v0, $v1
/* D3C338 80241D68 50400001 */  beql      $v0, $zero, .L80241D70
/* D3C33C 80241D6C AE000074 */   sw       $zero, 0x74($s0)
.L80241D70:
/* D3C340 80241D70 8E020078 */  lw        $v0, 0x78($s0)
/* D3C344 80241D74 8E0300A0 */  lw        $v1, 0xa0($s0)
/* D3C348 80241D78 0043102A */  slt       $v0, $v0, $v1
/* D3C34C 80241D7C 50400001 */  beql      $v0, $zero, .L80241D84
/* D3C350 80241D80 AE000078 */   sw       $zero, 0x78($s0)
.L80241D84:
/* D3C354 80241D84 8E02007C */  lw        $v0, 0x7c($s0)
/* D3C358 80241D88 8E0300A4 */  lw        $v1, 0xa4($s0)
/* D3C35C 80241D8C 0043102A */  slt       $v0, $v0, $v1
/* D3C360 80241D90 50400001 */  beql      $v0, $zero, .L80241D98
/* D3C364 80241D94 AE00007C */   sw       $zero, 0x7c($s0)
.L80241D98:
/* D3C368 80241D98 8FBF0014 */  lw        $ra, 0x14($sp)
/* D3C36C 80241D9C 8FB00010 */  lw        $s0, 0x10($sp)
/* D3C370 80241DA0 0000102D */  daddu     $v0, $zero, $zero
/* D3C374 80241DA4 03E00008 */  jr        $ra
/* D3C378 80241DA8 27BD0018 */   addiu    $sp, $sp, 0x18
