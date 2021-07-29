.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_entity_model_D
/* B8888 80122188 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B888C 8012218C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B8890 80122190 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B8894 80122194 AFBF0020 */  sw        $ra, 0x20($sp)
/* B8898 80122198 80420070 */  lb        $v0, 0x70($v0)
/* B889C 8012219C 10400004 */  beqz      $v0, .L801221B0
/* B88A0 801221A0 27AA0010 */   addiu    $t2, $sp, 0x10
/* B88A4 801221A4 30820800 */  andi      $v0, $a0, 0x800
/* B88A8 801221A8 10400034 */  beqz      $v0, .L8012227C
/* B88AC 801221AC 00000000 */   nop
.L801221B0:
/* B88B0 801221B0 2402F7FF */  addiu     $v0, $zero, -0x801
/* B88B4 801221B4 00822024 */  and       $a0, $a0, $v0
/* B88B8 801221B8 3C038015 */  lui       $v1, %hi(gCurrentEntityModelList)
/* B88BC 801221BC 8C634370 */  lw        $v1, %lo(gCurrentEntityModelList)($v1)
/* B88C0 801221C0 00041080 */  sll       $v0, $a0, 2
/* B88C4 801221C4 00431021 */  addu      $v0, $v0, $v1
/* B88C8 801221C8 8C490000 */  lw        $t1, ($v0)
/* B88CC 801221CC 1120002B */  beqz      $t1, .L8012227C
/* B88D0 801221D0 00000000 */   nop
/* B88D4 801221D4 8D280000 */  lw        $t0, ($t1)
/* B88D8 801221D8 11000028 */  beqz      $t0, .L8012227C
/* B88DC 801221DC 31020100 */   andi     $v0, $t0, 0x100
/* B88E0 801221E0 14400026 */  bnez      $v0, .L8012227C
/* B88E4 801221E4 31020020 */   andi     $v0, $t0, 0x20
/* B88E8 801221E8 14400024 */  bnez      $v0, .L8012227C
/* B88EC 801221EC 24020001 */   addiu    $v0, $zero, 1
/* B88F0 801221F0 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* B88F4 801221F4 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* B88F8 801221F8 00621004 */  sllv      $v0, $v0, $v1
/* B88FC 801221FC 01021024 */  and       $v0, $t0, $v0
/* B8900 80122200 1040001E */  beqz      $v0, .L8012227C
/* B8904 80122204 35020200 */   ori      $v0, $t0, 0x200
/* B8908 80122208 AD220000 */  sw        $v0, ($t1)
/* B890C 8012220C 25220018 */  addiu     $v0, $t1, 0x18
/* B8910 80122210 24A30040 */  addiu     $v1, $a1, 0x40
.L80122214:
/* B8914 80122214 8CAB0000 */  lw        $t3, ($a1)
/* B8918 80122218 8CAC0004 */  lw        $t4, 4($a1)
/* B891C 8012221C 8CAD0008 */  lw        $t5, 8($a1)
/* B8920 80122220 8CAE000C */  lw        $t6, 0xc($a1)
/* B8924 80122224 AC4B0000 */  sw        $t3, ($v0)
/* B8928 80122228 AC4C0004 */  sw        $t4, 4($v0)
/* B892C 8012222C AC4D0008 */  sw        $t5, 8($v0)
/* B8930 80122230 AC4E000C */  sw        $t6, 0xc($v0)
/* B8934 80122234 24A50010 */  addiu     $a1, $a1, 0x10
/* B8938 80122238 14A3FFF6 */  bne       $a1, $v1, .L80122214
/* B893C 8012223C 24420010 */   addiu    $v0, $v0, 0x10
/* B8940 80122240 3C018015 */  lui       $at, %hi(D_80154374)
/* B8944 80122244 AC264374 */  sw        $a2, %lo(D_80154374)($at)
/* B8948 80122248 81230004 */  lb        $v1, 4($t1)
/* B894C 8012224C 3C028012 */  lui       $v0, %hi(appendGfx_entity_model)
/* B8950 80122250 24421184 */  addiu     $v0, $v0, %lo(appendGfx_entity_model)
/* B8954 80122254 AD27005C */  sw        $a3, 0x5c($t1)
/* B8958 80122258 AD490008 */  sw        $t1, 8($t2)
/* B895C 8012225C AD42000C */  sw        $v0, 0xc($t2)
/* B8960 80122260 AD430000 */  sw        $v1, ($t2)
/* B8964 80122264 8D220000 */  lw        $v0, ($t1)
/* B8968 80122268 0140202D */  daddu     $a0, $t2, $zero
/* B896C 8012226C 3042F000 */  andi      $v0, $v0, 0xf000
/* B8970 80122270 00021202 */  srl       $v0, $v0, 8
/* B8974 80122274 0C047644 */  jal       queue_render_task
/* B8978 80122278 AD420004 */   sw       $v0, 4($t2)
.L8012227C:
/* B897C 8012227C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B8980 80122280 03E00008 */  jr        $ra
/* B8984 80122284 27BD0028 */   addiu    $sp, $sp, 0x28
